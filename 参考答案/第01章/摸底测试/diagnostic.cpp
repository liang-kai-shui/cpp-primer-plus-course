// ============================================================
//  L01 · 摸底测试
// ------------------------------------------------------------
//  目的：摸清你的真实水平，好决定后面的内容从哪里开始讲。
//
//  【怎么用】
//    1. 打开这个文件，实现下面 10 个函数
//    2. 每实现一个，按 Ctrl+S 保存，然后运行一次
//       （VS Code 里按 Ctrl+Alt+N，或者对着文件右键 → Run Code）
//    3. 看输出里哪些是 [通过]、哪些是 [未通过]
//    4. 全部做完（或卡住了）就停下来看结果
//
//  【最重要的规矩】
//    做不出来就让它空着（保持原样，测试会显示 [未通过]）。
//    ★ 千万不要去问 AI 要答案 ★
//    这份测试的价值全在"真实"两个字上。查出的是"AI 会什么"而不是
//    "你会什么"，后面就会按错误的起点安排内容——浪费的是你自己的时间。
//    空着不丢人，这份测试要的就是知道你哪里不会。
//
//  【难度标记】
//    [基础]  = 学过编程就应该会
//    [进阶]  = 需要想一下
//    [探测]  = 故意放这儿的，看你会不会。不会很正常，直接跳过。
//
//  【注意】函数原型（声明）已经给好了，不要改它们的名字、
//          参数类型、返回类型。只填函数体。
//          这本身就是一项能力：照着接口实现功能。
// ============================================================

// ---- 中文控制台兼容处理（无需任何配置，可整段忽略）----
// Windows 下把控制台输出代码页切成 UTF-8，避免中文乱码；
// 非 Windows 平台、或没有 utf8_console.h 时自动跳过，不影响编译和运行。
#if defined(__has_include)
#  if __has_include(<utf8_console.h>)
#    include <utf8_console.h>
#  elif defined(_WIN32)
#    include <windows.h>
namespace { struct Utf8ConsoleInit { Utf8ConsoleInit() {
    SetConsoleOutputCP(65001); SetConsoleCP(65001); } }; Utf8ConsoleInit g_utf8_init; }
#  endif
#elif defined(_WIN32)
#  include <windows.h>
namespace { struct Utf8ConsoleInit { Utf8ConsoleInit() {
    SetConsoleOutputCP(65001); SetConsoleCP(65001); } }; Utf8ConsoleInit g_utf8_init; }
#endif

#include <iostream>
#include <string>
#include <vector>

// ============================================================
//  你要实现的 10 个函数（原型）
// ============================================================
int          sum_to(int n);                                       // 1  [基础]
bool         is_prime(int n);                                     // 2  [基础]
int          count_vowels(const std::string& s);                  // 3  [基础]
void         swap_ints(int& a, int& b);                           // 4  [探测] 引用
double       average(const std::vector<int>& v);                  // 5  [基础]
std::string  reverse_str(const std::string& s);                   // 6  [基础]
int          find_max(const std::vector<int>& v);                 // 7  [基础]
std::vector<int> fib(int n);                                      // 8  [进阶]
void         sort_vec(std::vector<int>& v);                       // 9  [进阶]
const int*   find_ptr(const int* arr, int size, int target);      // 10 [探测] 指针


// ============================================================
//  1 [基础] 求 1 + 2 + ... + n
//     例：sum_to(10) 应返回 55
//     例：sum_to(0)  应返回 0
//     例：sum_to(100) 应返回 5050
// ============================================================
int sum_to(int n)
{
    (void)n;    // 占位：表示"参数暂时没用到"。实现后把这行删掉。
    // TODO: 在这里写你的代码
    return 0;
}


// ============================================================
//  2 [基础] 判断 n 是不是质数（素数：只能被 1 和自身整除，且 > 1）
//     例：is_prime(2)  == true
//     例：is_prime(7)  == true
//     例：is_prime(1)  == false   ← 注意这个边界
//     例：is_prime(91) == false   ← 91 = 7 × 13
// ============================================================
bool is_prime(int n)
{
    (void)n;
    // TODO
    return false;
}


// ============================================================
//  3 [基础] 统计字符串里元音字母的个数
//     元音 = a e i o u（大小写都算）
//     例：count_vowels("Hello World") == 3   (e, o, o)
//     例：count_vowels("AEIOU")       == 5
//     例：count_vowels("xyz")         == 0
// ============================================================
int count_vowels(const std::string& s)
{
    (void)s;
    // TODO
    return 0;
}


// ============================================================
//  4 [探测] 交换两个整数的值
//     例：int a=1, b=2;  swap_ints(a, b);  之后 a==2, b==1
//
//     提示：注意参数里的 & 符号。想一想：如果函数里写
//           `int t = a; a = b; b = t;`
//           调用方的 a、b 会变吗？为什么？
//     ★ 如果不知道 & 是什么意思，就空着，这是第 8 章的内容。
// ============================================================
void swap_ints(int& a, int& b)
{
    (void)a;
    (void)b;
    // TODO
}


// ============================================================
//  5 [基础] 求平均值
//     例：average({1,2,3,4}) == 2.5
//     例：average({5})       == 5.0
//     例：average({})        == 0.0   ← 空数组要处理，别除以 0
//
//     注意：返回类型是 double，不是 int。
//           average({1,2}) 应该是 1.5，不是 1。
// ============================================================
double average(const std::vector<int>& v)
{
    (void)v;
    // TODO
    return 0.0;
}


// ============================================================
//  6 [基础] 反转字符串
//     例：reverse_str("abc")   == "cba"
//     例：reverse_str("hello") == "olleh"
//     例：reverse_str("")      == ""
// ============================================================
std::string reverse_str(const std::string& s)
{
    (void)s;
    // TODO
    return "";
}


// ============================================================
//  7 [基础] 求数组中的最大值
//     例：find_max({3,7,2,9,1}) == 9
//     例：find_max({-5,-1,-9})  == -1   ← 全是负数也要对
//     例：find_max({42})        == 42
//     （测试保证数组非空，不用处理空数组）
// ============================================================
int find_max(const std::vector<int>& v)
{
    (void)v;
    // TODO
    return 0;
}


// ============================================================
//  8 [进阶] 返回斐波那契数列的前 n 项
//     定义：f(1)=1, f(2)=1, f(k)=f(k-1)+f(k-2)
//     例：fib(7) == {1, 1, 2, 3, 5, 8, 13}
//     例：fib(1) == {1}
//     例：fib(0) == {}          ← 返回空 vector
// ============================================================
std::vector<int> fib(int n)
{
    (void)n;
    // TODO
    return std::vector<int>();
}


// ============================================================
//  9 [进阶] 把数组从小到大排序（原地排序，直接修改传进来的 v）
//     例：v = {5,2,8,1};  sort_vec(v);  之后 v == {1,2,5,8}
//
//     用什么排序都行：冒泡、选择、插入……
//     ★ 不许调用 std::sort，我要看你自己写循环。
// ============================================================
void sort_vec(std::vector<int>& v)
{
    (void)v;
    // TODO
}


// ============================================================
//  10 [探测] 在数组里查找 target，返回指向它的指针；找不到返回 nullptr
//     例：int a[] = {10,20,30};  find_ptr(a, 3, 20) 应返回 &a[1]
//          *(find_ptr(a, 3, 20)) == 20
//     例：find_ptr(a, 3, 99) 应返回 nullptr
//
//     ★ 如果不知道"指针"是什么，直接跳过——这是第 4 章的内容，
//       我会把指针当成重点给你讲。
// ============================================================
const int* find_ptr(const int* arr, int size, int target)
{
    (void)arr;
    (void)size;
    (void)target;
    // TODO
    return nullptr;
}


// ============================================================
//  ↓↓↓ 以下全部是测试代码，不要修改 ↓↓↓
//      你只管实现上面的函数，这里会自动帮你检查。
// ============================================================

static int g_pass = 0;
static int g_fail = 0;

static std::string to_str(int v)    { return std::to_string(v); }
static std::string to_str(bool v)   { return v ? "true" : "false"; }
static std::string to_str(const std::string& v) { return "\"" + v + "\""; }
static std::string to_str(const std::vector<int>& v)
{
    std::string r = "{";
    for (std::size_t i = 0; i < v.size(); ++i)
    {
        if (i) r += ", ";
        r += std::to_string(v[i]);
    }
    return r + "}";
}

static void report(bool ok, const std::string& title,
                   const std::string& expected, const std::string& actual)
{
    if (ok) { ++g_pass; std::cout << "    [通过] " << title << "\n"; }
    else
    {
        ++g_fail;
        std::cout << "    [未通过] " << title << "\n"
                  << "             期望: " << expected << "\n"
                  << "             实际: " << actual << "\n";
    }
}

int main()
{
    std::cout << "\n";
    std::cout << "==================================================\n";
    std::cout << "        L01 诊断作业 · 自动测试\n";
    std::cout << "==================================================\n\n";

    // ---- 1 ----
    std::cout << "[第 1 题] sum_to\n";
    report(sum_to(10) == 55,  "sum_to(10) == 55",   "55",   to_str(sum_to(10)));
    report(sum_to(0)  == 0,   "sum_to(0) == 0",     "0",    to_str(sum_to(0)));
    report(sum_to(100) == 5050, "sum_to(100) == 5050", "5050", to_str(sum_to(100)));

    // ---- 2 ----
    std::cout << "[第 2 题] is_prime\n";
    report(is_prime(2)  == true,  "is_prime(2) == true",  "true",  to_str(is_prime(2)));
    report(is_prime(7)  == true,  "is_prime(7) == true",  "true",  to_str(is_prime(7)));
    report(is_prime(1)  == false, "is_prime(1) == false", "false", to_str(is_prime(1)));
    report(is_prime(91) == false, "is_prime(91) == false (91=7x13)", "false", to_str(is_prime(91)));

    // ---- 3 ----
    std::cout << "[第 3 题] count_vowels\n";
    report(count_vowels("Hello World") == 3, "count_vowels(\"Hello World\") == 3", "3", to_str(count_vowels("Hello World")));
    report(count_vowels("AEIOU") == 5, "count_vowels(\"AEIOU\") == 5", "5", to_str(count_vowels("AEIOU")));
    report(count_vowels("xyz") == 0, "count_vowels(\"xyz\") == 0", "0", to_str(count_vowels("xyz")));

    // ---- 4 ----
    std::cout << "[第 4 题] swap_ints\n";
    {
        int a = 1, b = 2;
        swap_ints(a, b);
        report(a == 2 && b == 1, "swap_ints(1,2) 后 a==2 且 b==1",
               "a=2, b=1", "a=" + std::to_string(a) + ", b=" + std::to_string(b));
    }

    // ---- 5 ----
    std::cout << "[第 5 题] average\n";
    {
        std::vector<int> v1{1, 2, 3, 4};
        std::vector<int> v2{1, 2};
        std::vector<int> v3;
        double a1 = average(v1), a2 = average(v2), a3 = average(v3);
        report(a1 > 2.499 && a1 < 2.501, "average({1,2,3,4}) == 2.5", "2.5", std::to_string(a1));
        report(a2 > 1.499 && a2 < 1.501, "average({1,2}) == 1.5  <- 别丢掉小数", "1.5", std::to_string(a2));
        report(a3 == 0.0, "average({}) == 0.0  <- 别除以 0", "0.0", std::to_string(a3));
    }

    // ---- 6 ----
    std::cout << "[第 6 题] reverse_str\n";
    report(reverse_str("abc") == "cba",   "reverse_str(\"abc\") == \"cba\"",   "\"cba\"",   to_str(reverse_str("abc")));
    report(reverse_str("hello") == "olleh", "reverse_str(\"hello\") == \"olleh\"", "\"olleh\"", to_str(reverse_str("hello")));
    report(reverse_str("") == "",         "reverse_str(\"\") == \"\"",         "\"\"",      to_str(reverse_str("")));

    // ---- 7 ----
    std::cout << "[第 7 题] find_max\n";
    report(find_max(std::vector<int>{3, 7, 2, 9, 1}) == 9,  "find_max({3,7,2,9,1}) == 9",  "9",  to_str(find_max(std::vector<int>{3, 7, 2, 9, 1})));
    report(find_max(std::vector<int>{-5, -1, -9}) == -1,    "find_max({-5,-1,-9}) == -1",  "-1", to_str(find_max(std::vector<int>{-5, -1, -9})));
    report(find_max(std::vector<int>{42}) == 42,            "find_max({42}) == 42",        "42", to_str(find_max(std::vector<int>{42})));

    // ---- 8 ----
    std::cout << "[第 8 题] fib\n";
    {
        std::vector<int> e7{1, 1, 2, 3, 5, 8, 13};
        std::vector<int> e1{1};
        std::vector<int> e0;
        report(fib(7) == e7, "fib(7) == {1,1,2,3,5,8,13}", to_str(e7), to_str(fib(7)));
        report(fib(1) == e1, "fib(1) == {1}",              to_str(e1), to_str(fib(1)));
        report(fib(0) == e0, "fib(0) == {}",               to_str(e0), to_str(fib(0)));
    }

    // ---- 9 ----
    std::cout << "[第 9 题] sort_vec\n";
    {
        std::vector<int> v{5, 2, 8, 1, 9, 3};
        std::vector<int> e{1, 2, 3, 5, 8, 9};
        sort_vec(v);
        report(v == e, "sort_vec({5,2,8,1,9,3}) == {1,2,3,5,8,9}", to_str(e), to_str(v));

        std::vector<int> v2{1};
        std::vector<int> e2{1};
        sort_vec(v2);
        report(v2 == e2, "sort_vec({1}) == {1}  <- 单个元素别崩", to_str(e2), to_str(v2));

        std::vector<int> v3;
        std::vector<int> e3;
        sort_vec(v3);
        report(v3 == e3, "sort_vec({}) == {}   <- 空数组别崩", to_str(e3), to_str(v3));
    }

    // ---- 10 ----
    std::cout << "[第 10 题] find_ptr  [探测题，不会就跳过]\n";
    {
        int a[] = {10, 20, 30};
        const int* p = find_ptr(a, 3, 20);
        report(p != nullptr && *p == 20, "*(find_ptr({10,20,30},3,20)) == 20",
               "指向 20 的指针", p ? ("*p=" + std::to_string(*p)) : "nullptr");

        const int* q = find_ptr(a, 3, 99);
        report(q == nullptr, "find_ptr(...,99) == nullptr", "nullptr",
               q ? ("*q=" + std::to_string(*q)) : "nullptr");
    }

    // ---- 汇总 ----
    std::cout << "\n==================================================\n";
    std::cout << "  通过 " << g_pass << " 项，未通过 " << g_fail << " 项";
    if (g_pass + g_fail > 0)
        std::cout << "   （正确率 " << (100 * g_pass / (g_pass + g_fail)) << "%）";
    std::cout << "\n==================================================\n";
    std::cout << "把这个结果记下来。做不出来很正常，\n";
    std::cout << "该看的是'未通过'的项 —— 它们指出了接下来要重点补的地方。\n\n";

    return 0;
}
