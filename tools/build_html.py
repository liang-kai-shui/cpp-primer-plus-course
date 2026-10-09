#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
把「可分发版」目录下的所有 Markdown 转成自带样式的 HTML。

特点：
  * 生成的 HTML **自带全部 CSS / JS / 代码高亮样式**，不依赖网络、不依赖外部文件
  * 镜像原目录结构；侧边导航的链接会带上正确的相对前缀（**子目录页面也能点**）
  * **默认深色模式**，右上角可切换浅色，选择记在浏览器 localStorage 里
  * 每页底部有「上一页 / 下一页」，可以按顺序一路读下去
  * 额外生成两种版本：
      docs/index.html      带侧边导航的在线阅读版（GitHub Pages 直接指向 docs/）
      docs/全一册.html      把讲义+练习+参考答案拼成一个单文件（最方便转发）

用法：
    python tools/build_html.py
"""

import atexit
import html
import os
import re
import shutil
import sys
import urllib.parse

try:
    import markdown
    from markdown.extensions.toc import TocExtension
    from pygments.formatters import HtmlFormatter
except ImportError:
    print("缺少依赖，请先安装：  pip install markdown pygments")
    sys.exit(1)

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "docs")   # 用 docs/ 是为了能让 GitHub Pages 直接指向它

# ================================================================ 样式
CSS = """
/* ============ 颜色变量：默认深色 ============ */
:root, [data-theme="dark"]{
  --bg:#14171a; --bg2:#1b1f24; --bg3:#232a31;
  --fg:#dfe3e8; --fg2:#b6bec8; --muted:#8b95a1;
  --line:#2b3138; --accent:#58a6ff;
  --code-bg:#0f1216; --quote-bg:#1b2027;
}
[data-theme="light"]{
  --bg:#fbfbfa; --bg2:#ffffff; --bg3:#f1f5f9;
  --fg:#22272e; --fg2:#3b434d; --muted:#6b7280;
  --line:#e5e7eb; --accent:#1f6feb;
  --code-bg:#f3f4f6; --quote-bg:#f8fafc;
}
*{box-sizing:border-box;}
html{scroll-behavior:smooth;}
body{
  margin:0; background:var(--bg); color:var(--fg);
  font-family:-apple-system,"Segoe UI","Microsoft YaHei","PingFang SC","Hiragino Sans GB",Roboto,sans-serif;
  font-size:16.5px; line-height:1.85;
  -webkit-font-smoothing:antialiased;
}
a{color:var(--accent); text-decoration:none;}
a:hover{text-decoration:underline;}

/* ============ 主题切换按钮 ============ */
#themeBtn{
  position:fixed; top:14px; right:18px; z-index:50;
  width:42px; height:42px; border-radius:50%;
  border:1px solid var(--line); background:var(--bg2); color:var(--fg);
  font-size:19px; line-height:1; cursor:pointer;
  box-shadow:0 2px 10px rgba(0,0,0,.22);
  display:flex; align-items:center; justify-content:center;
  transition:transform .15s ease, background .15s ease;
}
#themeBtn:hover{transform:scale(1.08); background:var(--bg3);}

.layout{display:flex; min-height:100vh;}

/* ============ 侧边导航 ============ */
nav{
  width:288px; flex:0 0 288px; background:var(--bg2);
  border-right:1px solid var(--line); padding:22px 0 80px;
  overflow-y:auto; position:sticky; top:0; height:100vh;
}
nav .brand{
  padding:0 20px 15px; font-weight:700; font-size:15px;
  border-bottom:1px solid var(--line); margin-bottom:12px; color:var(--fg);
}
nav .group{
  padding:16px 20px 6px; font-size:11.5px; color:var(--muted);
  letter-spacing:.1em; font-weight:600;
}
nav a{display:block; padding:6px 20px; font-size:14px; color:var(--fg2);
  border-left:3px solid transparent;}
nav a:hover{background:var(--bg3); text-decoration:none; color:var(--fg);}
nav a.active{color:var(--accent); font-weight:600;
  border-left-color:var(--accent); background:var(--bg3);}

main{flex:1; min-width:0; padding:46px 60px 120px; max-width:1120px;}
article{
  background:var(--bg2); border:1px solid var(--line);
  border-radius:12px; padding:40px 48px;
  box-shadow:0 1px 3px rgba(0,0,0,.10);
}

/* ============ 正文排版 ============ */
h1,h2,h3,h4{line-height:1.4; margin:1.7em 0 .7em; font-weight:700; scroll-margin-top:20px;}
h1{font-size:1.9em; margin-top:0; padding-bottom:.4em; border-bottom:2px solid var(--line);}
h2{font-size:1.42em; padding-bottom:.28em; border-bottom:1px solid var(--line);}
h3{font-size:1.16em;}
h4{font-size:1.03em; color:var(--fg2);}
p{margin:.8em 0;}
ul,ol{padding-left:1.65em;}
li{margin:.35em 0;}
strong{font-weight:700;}
hr{border:0; border-top:1px solid var(--line); margin:2.2em 0;}
img{max-width:100%;}

blockquote{
  margin:1.1em 0; padding:.85em 1.15em; background:var(--quote-bg);
  border-left:4px solid var(--accent); color:var(--fg2);
  border-radius:0 8px 8px 0;
}
blockquote p{margin:.4em 0;}
blockquote strong{color:var(--fg);}

/* ============ 表格 ============ */
table{
  border-collapse:collapse; width:100%; margin:1.2em 0;
  font-size:14.8px; display:block; overflow-x:auto;
}
th,td{border:1px solid var(--line); padding:9px 13px; text-align:left; vertical-align:top;}
th{background:var(--bg3); font-weight:600; white-space:nowrap;}
tbody tr:nth-child(even) td{background:rgba(127,127,127,.05);}

/* ============ 代码 ============ */
code{
  font-family:"Cascadia Code",Consolas,"SF Mono",Monaco,"Courier New","Microsoft YaHei",monospace;
  font-size:.885em; background:var(--code-bg); padding:.16em .42em;
  border-radius:4px; border:1px solid var(--line);
}
pre{
  background:var(--code-bg); border:1px solid var(--line); border-radius:9px;
  padding:15px 17px; overflow-x:auto; margin:1.1em 0; line-height:1.6;
}
pre code{background:none; padding:0; border:0; font-size:13.8px;}
.codehilite{background:var(--code-bg); border:1px solid var(--line);
  border-radius:9px; margin:1.1em 0;}
.codehilite pre{border:0; margin:0; background:none;}

/* ============ 本页目录 / 卡片 / 翻页 ============ */
.toc-box{
  background:var(--quote-bg); border:1px solid var(--line);
  border-radius:9px; padding:13px 22px; margin:1.3em 0;
}
.toc-box strong{display:block; margin-bottom:5px; color:var(--muted);
  font-size:13px; letter-spacing:.05em;}
.toc-box ul{margin:.35em 0; padding-left:1.3em;}
.toc-box a{color:var(--fg2);}
.toc-box a:hover{color:var(--accent);}

/* ============ 讲义页顶部的"卡住了去哪查"横幅 ============ */
.hintbar{
  background:var(--bg3); border:1px solid var(--line); border-radius:8px;
  padding:9px 15px; margin:0 0 1.5em; font-size:13.5px; color:var(--muted);
}
.hintbar a{font-weight:600;}

/* 超长的"本页目录"（比如术语表有 100+ 词条）折叠起来，别把正文挤下去 */
details.toc-box summary{
  cursor:pointer; color:var(--muted); font-size:13.5px;
  font-weight:600; letter-spacing:.03em; user-select:none;
}
details.toc-box summary:hover{color:var(--accent);}
details.toc-box[open] summary{margin-bottom:.5em;}

.cards{display:grid; grid-template-columns:repeat(auto-fill,minmax(300px,1fr));
  gap:16px; margin:24px 0;}
.card{background:var(--bg2); border:1px solid var(--line); border-radius:11px;
  padding:19px 21px; transition:transform .15s ease, border-color .15s ease;}
.card:hover{transform:translateY(-2px); border-color:var(--accent);}
.card h3{margin:0 0 8px; font-size:1.06em;}
.card p{margin:0; color:var(--muted); font-size:14px; line-height:1.65;}

.pager{display:flex; justify-content:space-between; gap:14px; margin-top:34px;
  padding-top:20px; border-top:1px solid var(--line);}
.pager a{flex:1; padding:11px 16px; background:var(--bg3); border:1px solid var(--line);
  border-radius:9px; font-size:14px; color:var(--fg2);}
.pager a:hover{border-color:var(--accent); color:var(--accent); text-decoration:none;}
.pager a.next{text-align:right;}
.pager a.disabled{opacity:.35; pointer-events:none;}

.author-line{color:var(--muted); font-size:14px;}
.author-line a{font-weight:600;}
.footer{display:flex; flex-wrap:wrap; justify-content:space-between; gap:8px 24px;
  margin-top:26px; padding-top:14px; border-top:1px solid var(--line);
  color:var(--muted); font-size:13.5px;}

/* ============ 移动端 ============ */
@media (max-width:900px){
  nav{display:none;}
  main{padding:18px 12px 60px;}
  article{padding:22px 17px; border-radius:8px;}
  #themeBtn{top:10px; right:10px; width:38px; height:38px;}
}
"""

PAGE = """<!DOCTYPE html>
<html lang="zh-CN" data-theme="dark">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<meta name="author" content="凉开水">
<title>{title}</title>
<script>
/* 在页面渲染前先定好主题，避免"白屏闪一下" */
(function(){{
  try{{
    var t = localStorage.getItem('cppcourse-theme') || 'dark';
    document.documentElement.setAttribute('data-theme', t);
  }}catch(e){{}}
}})();
</script>
<style>{css}</style>
</head>
<body>
<button id="themeBtn" title="切换深色 / 浅色">🌙</button>
<div class="layout">
{nav}
<main><article>
{body}
{pager}
<footer class="footer">
<span>{footer}</span>
<span>课程作者：<a href="https://lksme.dpdns.org/" rel="author">凉开水</a></span>
</footer>
</article></main>
</div>
<script>
(function(){{
  var btn = document.getElementById('themeBtn');
  function sync(){{
    var t = document.documentElement.getAttribute('data-theme') || 'dark';
    btn.textContent = (t === 'dark') ? '☀️' : '🌙';
    btn.title = (t === 'dark') ? '切换到浅色' : '切换到深色';
  }}
  btn.addEventListener('click', function(){{
    var t = document.documentElement.getAttribute('data-theme') || 'dark';
    t = (t === 'dark') ? 'light' : 'dark';
    document.documentElement.setAttribute('data-theme', t);
    try{{ localStorage.setItem('cppcourse-theme', t); }}catch(e){{}}
    sync();
  }});
  sync();
}})();
</script>
</body>
</html>
"""

def zh_slugify(value, separator):
    """生成标题锚点 id。

    ⚠️ 必须自己写：markdown 自带的 slugify 默认会把【所有非 ASCII 字符】剥掉，
    于是「## 本课目标」的 id 会变成空串（再被去重成 `_1`），
    「## 1.1 人和计算机…」变成 `11` —— 既难读又容易撞车，
    更麻烦的是手写的 GitHub 风格锚点（`#1-电脑到底在干什么`）全都对不上。
    这里保留中文（Python 3 的 \\w 本来就匹配中文）。
    """
    value = value.strip().lower()
    value = re.sub(r"[^\w\s-]", "", value)          # 去掉标点和「」等符号，保留中文
    value = re.sub(r"[%s\s]+" % re.escape(separator), separator, value)
    return value.strip(separator)


MD_EXT = ["extra", "sane_lists", TocExtension(permalink=False, toc_depth="2-4",
                                              slugify=zh_slugify), "codehilite"]
MD_CFG = {"codehilite": {"noclasses": False, "guess_lang": False}}

# 两套代码高亮配色，按主题作用域隔离（关键：不能用 noclasses=True 的内联颜色，否则深色模式下代码是浅色底）
PYG_CSS = (
    HtmlFormatter(style="monokai").get_style_defs('[data-theme="dark"] .codehilite')
    + "\n"
    + HtmlFormatter(style="friendly").get_style_defs('[data-theme="light"] .codehilite')
    + '\n[data-theme="dark"] .codehilite, [data-theme="dark"] .codehilite pre{background:transparent;}\n'
)

PAGE_ORDER = {"README.md": 0, "附录": 0.5, "讲义": 1, "练习": 2, "参考答案": 3}


def md_to_html(text):
    md = markdown.Markdown(extensions=MD_EXT, extension_configs=MD_CFG)
    body = md.convert(text)
    body = re.sub(r'href="([^"]+?)\.md(#[^"]*)?"', r'href="\1.html\2"', body)
    return body, getattr(md, "toc", "")


def reroot(html_text, page_rel):
    """把一页里的相对链接，改写成「相对于 html/ 根目录」的形式。

    全一册把所有页面拍平到一个文件里，原来带目录前缀的链接（比如讲义页里的
    `../附录/术语表.html`、参考答案页里的 `代码/`）会失效。
    先把它们按【原页面所在目录】解析成绝对一点的路径，就能继续用。
    """
    base = os.path.dirname(page_rel)          # 例如 '讲义' / '参考答案/第01章'

    def repl(m):
        attr, url = m.group(1), m.group(2)
        if url.startswith(("http://", "https://", "mailto:", "data:", "#", "javascript:")):
            return m.group(0)
        path, _, frag = url.partition("#")
        if not path:
            return m.group(0)
        joined = os.path.normpath(os.path.join(base, urllib.parse.unquote(path)))
        joined = joined.replace("\\", "/")
        if joined.startswith(".."):
            return m.group(0)                 # 指到 html/ 外面去了，保持原样
        return '%s="%s%s"' % (attr, joined, ("#" + frag) if frag else "")

    return re.sub(r'(href|src)="([^"]+)"', repl, html_text)


def collect(root):
    items = []
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames[:] = [d for d in dirnames if d not in ("docs", "html", "__pycache__", ".git")]
        for fn in sorted(filenames):
            if fn.lower().endswith(".md"):
                rel = os.path.relpath(dirpath, root)
                rel = "" if rel == "." else rel
                items.append((rel, fn, os.path.join(dirpath, fn)))
    return items


def build_nav(items, current_rel, prefix=""):
    """prefix = 当前页到根目录的相对路径（如 '../'）。
       ★ 修复点：导航里的 href 必须加上它，否则子目录页面点任何链接都是 404。"""
    by_dir = {}
    for rel, fn, _ in items:
        by_dir.setdefault(rel.replace("\\", "/"), []).append(fn)

    def link(rel, fn, label=None):
        target = (rel + "/" if rel else "") + fn[:-3] + ".html"
        cls = ' class="active"' if target == current_rel else ""
        return '<a href="%s%s"%s>%s</a>' % (prefix, target, cls,
                                            html.escape(label or fn[:-3]))

    out = ['<nav><div class="brand">C++ 入门课程</div>']
    if "README.md" in by_dir.get("", []):
        out.append(link("", "README.md", "课程说明"))
    for dirname in ("附录", "讲义", "练习", "参考答案"):
        files = by_dir.get(dirname, [])
        sub = sorted(d for d in by_dir if d.startswith(dirname + "/"))
        if not files and not sub:
            continue
        out.append('<div class="group">%s</div>' % html.escape(dirname))
        for fn in files:
            out.append(link(dirname, fn))
        for d in sub:
            for fn in by_dir[d]:
                out.append(link(d, fn, d.split("/", 1)[1] + " · " + fn[:-3]))
    out.append("</nav>")
    return "\n".join(out)


def preserve_docs_pdfs():
    """重建 docs/ 时保留其中由 Git LFS 管理的教材 PDF。"""
    if not os.path.isdir(OUT):
        return lambda: None
    names = [fn for fn in os.listdir(OUT)
             if fn.lower().endswith(".pdf") and os.path.isfile(os.path.join(OUT, fn))]
    if not names:
        return lambda: None

    hold = os.path.join(ROOT, ".docs_pdf_backup")
    if os.path.exists(hold):
        raise RuntimeError("发现未处理的 .docs_pdf_backup；请先检查并恢复其中的 PDF")
    os.mkdir(hold)
    for fn in names:
        os.replace(os.path.join(OUT, fn), os.path.join(hold, fn))

    def restore():
        os.makedirs(OUT, exist_ok=True)
        for fn in names:
            saved = os.path.join(hold, fn)
            if os.path.isfile(saved):
                os.replace(saved, os.path.join(OUT, fn))
        if os.path.isdir(hold) and not os.listdir(hold):
            os.rmdir(hold)

    atexit.register(restore)  # 生成中途抛出异常时也恢复
    return restore


def main():
    restore_pdfs = preserve_docs_pdfs()
    if os.path.isdir(OUT):
        shutil.rmtree(OUT)
    os.makedirs(OUT)

    items = collect(ROOT)
    if not items:
        print("没找到任何 .md 文件")
        return
    print("找到 %d 个 Markdown 文件" % len(items))

    def sort_key(item):
        rel, fn, _ = item
        r = rel.replace("\\", "/")
        top = r.split("/")[0] if r else ""
        return (PAGE_ORDER.get(top if top else fn, 9), r, fn)

    ordered = [((r.replace("\\", "/") + "/") if r else "") + fn[:-3] + ".html"
               for r, fn, _ in sorted(items, key=sort_key)]

    css_all = CSS + "\n/* ===== 代码高亮（按主题隔离） ===== */\n" + PYG_CSS

    converted = {}
    for rel, fn, path in items:
        with open(path, encoding="utf-8") as f:
            text = f.read()

        # 先把路径信息算好，后面（横幅、导航、翻页）都要用
        rel_fwd = rel.replace("\\", "/") if rel else ""
        target_rel = ((rel_fwd + "/") if rel_fwd else "") + fn[:-3] + ".html"
        depth = rel_fwd.count("/") + 1 if rel_fwd else 0
        back = "../" * depth

        body, toc = md_to_html(text)

        # 讲义页顶部插一条"卡住了去哪查"的横幅（附录不存在就不显示，避免死链）
        if rel_fwd == "讲义":
            have = {fn2 for r2, fn2, _ in items if r2.replace("\\", "/") == "附录"}
            bits = []
            if "术语表.md" in have:
                bits.append('遇到看不懂的专有名词？→ <a href="%s附录/术语表.html">术语表</a>' % back)
            if "零基础起飞.md" in have:
                bits.append('电脑基础操作不熟（比如任务管理器、命令行）？→ '
                            '<a href="%s附录/零基础起飞.html">零基础起飞</a>' % back)
            if bits:
                body = '<div class="hintbar">%s</div>' % "&nbsp;&nbsp;·&nbsp;&nbsp;".join(bits) + body

        if toc:
            n = toc.count("<li>")
            if n > 25:      # 词条太多就把目录折起来（术语表有一百多条）
                body = ('<details class="toc-box"><summary>本页目录（%d 项，点击展开）</summary>%s</details>%s'
                        % (n, toc, body))
            else:
                body = '<div class="toc-box"><strong>本页目录</strong>%s</div>%s' % (toc, body)

        nav = build_nav(items, target_rel, prefix=back)

        pager = ""
        try:
            i = ordered.index(target_rel)
        except ValueError:
            i = -1
        if i >= 0:
            if i > 0:
                t = ordered[i - 1]
                prev_html = '<a class="prev" href="%s%s">← 上一页：%s</a>' % (
                    back, t, html.escape(t.split("/")[-1][:-5]))
            else:
                prev_html = '<a class="prev disabled">← 已是第一页</a>'
            if i < len(ordered) - 1:
                t = ordered[i + 1]
                nxt = '<a class="next" href="%s%s">下一页：%s →</a>' % (
                    back, t, html.escape(t.split("/")[-1][:-5]))
            else:
                nxt = '<a class="next disabled">已是最后一页 →</a>'
            pager = '<div class="pager">%s%s</div>' % (prev_html, nxt)

        page = PAGE.format(title=html.escape(fn[:-3]), css=css_all, nav=nav,
                           body=body, pager=pager,
                           footer='<a href="%sindex.html">← 返回总目录</a>' % back)
        outpath = os.path.join(OUT, target_rel.replace("/", os.sep))
        os.makedirs(os.path.dirname(outpath), exist_ok=True)
        with open(outpath, "w", encoding="utf-8", newline="\n") as f:
            f.write(page)
        converted[target_rel] = (fn[:-3], body)
        print("  " + target_rel)

    # 把非 md 文件也镜像一份（讲义里引用的 .cpp 要能在 HTML 版里打开）
    # 但 tools/ 和 .开头 的文件（.gitignore 等）不该进 docs/
    for dirpath, dirnames, filenames in os.walk(ROOT):
        dirnames[:] = [d for d in dirnames
                       if d not in ("docs", "html", "__pycache__", ".git", "tools", ".docs_pdf_backup")]
        for fn in filenames:
            if fn.lower().endswith(".md") or fn.startswith("."):
                continue
            src = os.path.join(dirpath, fn)
            rel = os.path.relpath(dirpath, ROOT)
            dst_dir = os.path.join(OUT, rel) if rel != "." else OUT
            os.makedirs(dst_dir, exist_ok=True)
            shutil.copy2(src, os.path.join(dst_dir, fn))

    # ---------- 首页 ----------
    wanted = [
        ("第01章", "程序怎么从一段文字变成能运行的软件；三类错误的分类框架"),
        ("第02章", "变量、语句、函数、输入输出；重点是函数原型与名称空间"),
        ("第03章", "整型家族、char 的本质、浮点数；整数除法与类型转换的坑"),
        ("第04章A", "数组、C 风格字符串的本质（\\0）、混合输入的陷阱"),
        ("第04章B", "结构、共用体、枚举；把不同类型的数据打包成一个整体"),
        ("第04章C", "指针、地址、new/delete 与动态数组"),
        ("第04章D", "指针算术、动态结构、array 与 vector"),
    ]
    cards = []
    for prefix, desc in wanted:
        for rel, fn, _ in items:
            if rel.replace("\\", "/") == "讲义" and fn.startswith(prefix):
                cards.append('<div class="card"><h3><a href="讲义/%s.html">%s</a></h3>'
                             '<p>%s</p></div>' % (fn[:-3], html.escape(fn[:-3]), html.escape(desc)))
                break

    primer = "附录/零基础起飞.html"
    primer_html = ('另外强烈建议先看 <strong><a href="%s">零基础起飞：电脑与编程的最基本概念</a></strong>，'
                   '那一篇把「什么是文件、什么是文件夹、什么是路径、什么是程序」'
                   '这些讲清楚了——没看过这些直接学会很吃力。' % primer
                   if os.path.exists(os.path.join(OUT, "附录", "零基础起飞.html"))
                   else "")

    idx = """
<h1>C++ 入门课程</h1>
<p>一套<strong>从零讲起</strong>的 C++ 自学材料，配合《C++ Primer Plus（第 6 版）》使用。</p>
<p class="author-line">课程作者：<a href="https://lksme.dpdns.org/" rel="author">凉开水</a> · 点击访问个人博客</p>
<blockquote><p><strong>第一次来，请先读 <a href="README.html">课程说明</a></strong>——
里面写了「需要准备什么环境」「怎么用这份材料」「遇到问题怎么办」。<br>%s</p></blockquote>
<div class="cards">%s</div>
<h2>其他入口</h2>
<ul>
<li><a href="附录/术语表.html">术语表</a>——所有专有名词的「人话解释」，卡住时随时查</li>
<li><a href="练习/第01章-练习.html">练习</a>——教材原题 + 动手实验，<strong>先做完再看答案</strong></li>
<li><a href="参考答案/第01章/复习题答案.html">参考答案</a>——编程练习代码 + 复习题答案</li>
<li><a href="示例代码/01_错误分类实验/A_missing_semicolon.cpp">示例代码</a>——讲义里引用的每个程序</li>
<li><a href="全一册.html">全一册（单文件）</a>——所有内容拼在一起，最方便转发</li>
</ul>
""" % (primer_html, "".join(cards))

    nav = build_nav(items, "index.html")
    with open(os.path.join(OUT, "index.html"), "w", encoding="utf-8", newline="\n") as f:
        f.write(PAGE.format(title="C++ 入门课程", css=css_all, nav=nav, body=idx,
                            pager="", footer="由 Markdown 自动生成"))

    # ---------- 全一册 ----------
    parts = []
    for key in ordered:
        if key in converted:
            t, b = converted[key]
            b = reroot(b, key)            # ★ 拍平后要让内部链接继续可用
            parts.append('<section><h1 style="margin-top:2.6em">%s</h1>%s</section>'
                         % (html.escape(t), b))
    single = PAGE.format(title="C++ 入门课程 · 全一册", css=css_all, nav="",
                         body="\n<hr>\n".join(parts), pager="",
                         footer="由 Markdown 自动生成 · 全一册")
    with open(os.path.join(OUT, "全一册.html"), "w", encoding="utf-8", newline="\n") as f:
        f.write(single)

    # GitHub Pages 用：告诉它别用 Jekyll 处理 docs/（顺便让构建快一点）
    with open(os.path.join(OUT, ".nojekyll"), "w", encoding="utf-8", newline="\n") as f:
        f.write("")

    restore_pdfs()

    print("\n完成 → %s" % OUT)
    print("  打开 docs/index.html 在线阅读（默认深色，右上角可切换）")
    print("  docs/全一册.html 是单文件版，最适合转发")


if __name__ == "__main__":
    main()
