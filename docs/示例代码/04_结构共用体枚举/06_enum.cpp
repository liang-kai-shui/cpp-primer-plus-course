// ============================================================
//  L05 · 示例 6：枚举 enum        （教材 4.6, p112-114）
// ------------------------------------------------------------
//  枚举 = 给一组整数起「有意义的名字」。
//  为什么需要？对比一下：
//      int  today = 3;        // 3 是星期几？读代码的人得去查
//      Week today = Wed;      // 一眼就懂
// ============================================================
#include <iostream>

// ---------- 基本用法：枚举量默认从 0 开始，依次 +1 ----------
enum Color { red, green, blue };                    // red=0, green=1, blue=2

// ---------- 可以自己指定值，后面的接着 +1（教材 4.6.1）----------
enum Week { Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun }; // Mon=1 .. Sun=7

// ---------- 也可以只指定一部分 ----------
enum Level { none = 0, low = 1, high = 10, extra };  // extra 自动 = 11

int main()
{
    using namespace std;

    // ---------- 枚举量的值 ----------
    cout << "===== 枚举量就是有名字的整数 =====\n";
    cout << "red=" << red << " green=" << green << " blue=" << blue << "\n";
    cout << "Mon=" << Mon << " Wed=" << Wed << " Sun=" << Sun << "\n";
    cout << "none=" << none << " low=" << low << " high=" << high << " extra=" << extra
         << "   <- extra 是 high+1\n";

    // ---------- 用枚举变量，代码能自解释 ----------
    Week today = Wed;
    cout << "\nWeek today = Wed;\n";
    cout << "  打印 today 出来是: " << today << "   <- 枚举量打印出来是【数字】，不是名字\n";

    // ---------- 可以比较 ----------
    if (today == Wed)
        cout << "  if (today == Wed) 成立\n";

    // ---------- 参与运算时会退化成整数 ----------
    cout << "  today + 1 = " << today + 1 << "   （Wed 是 3，加 1 得 4）\n";

    // ---------- 用途对比 ----------
    cout << "\n【用途对比】\n";
    int  oldStyle = 3;                 // 3 是什么意思？
    Week newStyle = Wed;               // 自解释
    cout << "  int  oldStyle = 3;        -> 打印出来 " << oldStyle
         << "，读代码的人得去查文档\n";
    cout << "  Week newStyle = Wed;      -> 打印出来 " << newStyle
         << "，一看就懂（虽然显示的还是数字）\n";

    // ---------- 底层类型与大小 ----------
    cout << "\n===== 底层类型（教材 4.6.2）=====\n";
    cout << "sizeof(Color) = " << sizeof(Color) << " 字节\n";
    cout << "sizeof(Week)  = " << sizeof(Week)  << " 字节\n";
    cout << "  底层整数类型由编译器选，规则只要求它「装得下所有枚举量」。\n";
    cout << "  ⚠️ 注意：规则只要求「装得下」，【不要求选最小的】。\n";
    cout << "     实测 Color 的范围只要 0..2，照样占 4 字节（就是 int）。\n";
    cout << "  所以不同枚举的 sizeof 可能不同 —— 别假设它一定是 4。\n";

    // ---------- 取值范围规则（教材 4.6.2）----------
    cout << "\n【取值范围的规则】\n";
    cout << "  上限 = 「大于最大枚举量的最小 2 的幂」减 1\n";
    cout << "         例：最大是 7  -> 2^3-1 = 7\n";
    cout << "             最大是 10 -> 2^4-1 = 15\n";
    cout << "  下限 = 若最小枚举量 >= 0，则是 0；否则是 -(2^n - 1)\n";
    cout << "  这条规则算出来的是「最少需要多大」，实际用多大还看编译器。\n";

    // ---------- ⚠️ 一个要注意的地方：枚举量名【不是】局部的 ----------
    cout << "\n【注意】普通 enum 的成员名会跑到外层作用域里：\n";
    cout << "  enum Color { red, green, blue }; 之后，red/green/blue 就是全局名字了。\n";
    cout << "  如果另一个 enum 也想要 red，就冲突了。\n";

    // ---------- C++11 的解法：enum class（作用域内枚举）----------
    cout << "\n===== C++11：enum class（作用域内枚举）=====\n";
    enum class Direction { north, south, east, west };
    Direction dir = Direction::north;          // ⚠️ 必须写 Direction::
    cout << "  enum class Direction { north, ... };\n";
    cout << "  Direction dir = Direction::north;   <- 必须带前缀\n";
    cout << "  好处 1：名字不冲突（Color::red 和 Other::red 可以共存）\n";
    cout << "  好处 2：不会隐式转换成 int，更安全\n";
    cout << "  代价 1：不能直接打印，要转型：\n";
    cout << "          cout << static_cast<int>(dir) = " << static_cast<int>(dir) << "\n";
    cout << "  代价 2：不能直接和 int 比较，要显式转换\n";
    cout << "  （第 10 章「类作用域」会再讲一次）\n";

    return 0;
}
