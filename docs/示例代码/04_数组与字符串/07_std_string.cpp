// ============================================================
//  L04 · 示例 7：std::string —— C 风格字符串的救星
//              （教材 4.3, p99-105）
// ------------------------------------------------------------
//  C 风格字符串（char 数组）有三大痛点：
//    1. 要手动管大小，写小了就溢出
//    2. 不能整体赋值：     s1 = s2;       编译错误
//    3. 不能用 == 比内容：  s1 == s2        比的是地址，不是文字
//  std::string 把这三个问题全解决了。
// ============================================================
#include <iostream>
#include <string>               // std::string 在这个头文件里
#include <cstring>              // strcmp 在这里

int main()
{
    using namespace std;

    // ---------- 1. 不用管大小：自动伸缩 ----------
    string s1 = "Hello";
    s1 = s1 + ", world!";               // 变长了？它自己重新分配内存
    cout << "s1 = " << s1 << "   长度 " << s1.size() << endl;

    // ---------- 2. 可以直接赋值 ----------
    string s2;
    s2 = s1;                            // 这才是正常的赋值
    cout << "s2 = s1; 之后 s2 = " << s2 << endl;

    // ---------- 3. 可以用 == 比较内容 ----------
    string a = "apple";
    string b = "apple";
    if (a == b)
        cout << "\n\"apple\" == \"apple\"  ->  true   （比较的是内容）\n";

    // 对比：C 风格字符串用 == 会怎样？
    char ca[] = "apple";
    char cb[] = "apple";
    cout << "C 风格：ca == cb  ->  " << (ca == cb)
         << "   <- 比的是【两个数组的地址】，不是内容！\n";
    cout << "  要比内容必须用 strcmp(ca, cb) == 0，结果是 "
         << (strcmp(ca, cb) == 0) << "\n";
    cout << "  ★ 这就是 std::string 更省心的地方 ★\n";

    // ---------- 常用操作 ----------
    string s = "Hello";
    cout << "\n===== 常用操作 =====\n";
    cout << "s.size()          = " << s.size() << "      (长度)\n";
    cout << "s[1]              = " << s[1] << "      (像数组一样用下标取字符)\n";
    cout << "s.empty()         = " << s.empty() << "      (是否为空)\n";
    s += " there";                          // 追加
    cout << "s += \" there\"     -> " << s << "\n";
    cout << "s.substr(0, 5)    = " << s.substr(0, 5) << "  (取子串)\n";
    cout << "s.find(\"there\")   = " << s.find("there") << "     (找位置，找不到返回 npos)\n";

    // ---------- 输入：string 也能用 getline ----------
    cout << "\n===== string 的输入 =====\n";
    cout << "请输入一整行（可以带空格）: ";
    string line;
    getline(cin, line);                 // 注意这里【不用】写大小！
    cout << "你输入了 " << line.size() << " 个字符：\"" << line << "\"\n";
    cout << "  ★ getline(cin, string) 不用管缓冲区大小，比 char 数组安全 ★\n";

    cout << "\n【结论】写 C++ 应该优先用 std::string，\n";
    cout << "        char 数组留给「必须和 C 交互」或「学原理」的场合。\n";

    return 0;
}