// ============================================================
//  L05 · 示例 5：共用体 union        （教材 4.5, p111-112）
// ------------------------------------------------------------
//  共用体 = 一种「多个成员共享同一块内存」的结构。
//  特点：同一时刻只能有一个成员有效 —— 写一个就会覆盖其他。
//  用途：省内存（当一块内存在不同时刻要存不同类型时）。
// ============================================================
#include <iostream>

union Value
{
    int    i;
    long   l;
    double d;
    char   bytes[8];
};

int main()
{
    using namespace std;

    cout << "sizeof(int)         = " << sizeof(int) << "\n";
    cout << "sizeof(long)        = " << sizeof(long) << "\n";
    cout << "sizeof(double)      = " << sizeof(double) << "\n";
    cout << "sizeof(char[8])     = " << sizeof(char[8]) << "\n";
    cout << "--------------------------------\n";
    cout << "sizeof(union Value) = " << sizeof(Value) << "\n";
    cout << "  ^ 等于【最大那个成员】的大小，而不是各成员之和！\n";

    Value v;

    // ---------- 写一个成员，其他成员就被覆盖了 ----------
    v.i = 65;
    cout << "\nv.i = 65   （写入 int）\n";
    cout << "  读 v.i = " << v.i << "\n";
    cout << "  读 v.d = " << v.d << "   <- 垃圾值（同一块内存被当成 double 解释）\n";

    v.d = 3.14159;
    cout << "\nv.d = 3.14159   （写入 double，覆盖了刚才的 i）\n";
    cout << "  读 v.d = " << v.d << "\n";
    cout << "  读 v.i = " << v.i << "   <- 已经不是 65 了\n";

    // ---------- 看它们的地址：完全一样 ----------
    cout << "\n&v.i = " << &v.i << "\n";
    cout << "&v.d = " << &v.d << "\n";
    cout << "  ^ 地址完全相同 —— 这就是「共用」的含义\n";

    cout << "\n【关键理解】\n";
    cout << "  union 不记录「当前哪个成员是有效的」。\n";
    cout << "  你读一个不是最后写入的成员，它【不会报错】，只会给你垃圾值。\n";
    cout << "  所以正确用法是：自己用一个额外的变量记住「现在存的是什么类型」。\n";

    // ---------- 常见用法：union + 标签（叫「带标签的联合」）----------
    cout << "\n===== 常见用法：union + 一个标签 =====\n";
    struct Variant
    {
        char tag;                      // 标签：'i' 表示存的是 int，'d' 表示存的是 double
        union { int i; double d; };    // 匿名共用体（C++11 支持），成员直接叫 .i / .d
    };

    Variant a;
    a.tag = 'i';
    a.i = 42;

    Variant b;
    b.tag = 'd';
    b.d = 2.718;

    cout << "  a: tag=" << a.tag << "  值=" << a.i << "\n";
    cout << "  b: tag=" << b.tag << "  值=" << b.d << "\n";
    cout << "  用 tag 记住类型，读的时候就不会读错成员。\n";
    cout << "  （这种结构在文件格式解析、网络协议、脚本引擎里很常见）\n";

    cout << "\n【用不用？】学习阶段几乎用不到 union。\n";
    cout << "  它的主要价值是「省内存」和「看同一块内存的不同解释」。\n";
    cout << "  现代 C++ 里很多场景被 std::variant（第 18 章之后）替代了。\n";
    cout << "  现在只需要认识它、知道它和 struct 的区别就够了。\n";

    return 0;
}
