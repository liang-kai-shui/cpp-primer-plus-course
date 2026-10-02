// ============================================================
//  示例 5：类型转换（隐式 vs 显式）
//              （对应教材 3.4.4 p79-83、复习题第 9 题）
// ============================================================
#include <iostream>

int main()
{
    using namespace std;

    cout << "===== 隐式转换：编译器自动做的 =====\n";
    int    i = 3.99;            // double -> int
    double x = 7 / 2;           // 注意！右边先按整数算
    double y = 7.0 / 2;         // 这样才对
    cout << "int i = 3.99;      i = " << i << "   <- 直接砍掉小数，不四舍五入\n";
    cout << "double x = 7 / 2;  x = " << x << "   <- 右边先算成 3，再转成 3.0\n";
    cout << "double y = 7.0 / 2;y = " << y << " <- 有 double 参与，才是 3.5\n";

    cout << "\n【转换规则记两条】\n";
    cout << "  1. 小类型 -> 大类型：安全（char->int->long->double）\n";
    cout << "  2. 大类型 -> 小类型：可能丢数据（double->int 丢小数）\n";
    cout << "  3. 表达式中只要有 double，整个表达式就按 double 算\n";

    cout << "\n===== 显式转换（强制类型转换）=====\n";
    double pi = 3.14159;
    cout << "(int)pi                  = " << (int)pi << "        <- C 风格\n";
    cout << "static_cast<int>(pi)     = " << static_cast<int>(pi) << "        <- C++ 风格（推荐）\n";
    cout << "int(pi)                  = " << int(pi) << "        <- 函数式写法\n";

    cout << "\n===== 为什么推荐 static_cast？=====\n";
    cout << "因为它一眼就能在代码里被搜出来 —— 类型转换是 bug 高发区，\n";
    cout << "能搜到就能审查。C 风格的 (int) 混在括号里根本找不出来。\n";

    cout << "\n===== 复习题第 9 题：两个 double 相加 =====\n";
    // 特意选这两个数：小数部分加起来会进位，才能看出两种写法不同
    double x1 = 3.9, x2 = 4.9;
    int sum1 = (int)x1 + (int)x2;                 // 作为整数相加
    int sum2 = (int)(x1 + x2);                    // 作为 double 相加再转 int
    cout << "x1 = " << x1 << ", x2 = " << x2 << "\n";
    cout << "先各自转 int 再相加 : (int)x1 + (int)x2   = " << sum1 << "   (3 + 4，小数被各自砍掉)\n";
    cout << "先相加再转 int      : (int)(x1 + x2)      = " << sum2 << "   (int)8.8\n";
    cout << "-> 两条语句**不等价**，差 1\n";
    cout << "   注意：如果 x1=3.7、x2=4.2，两个结果会**碰巧**都是 7，\n";
    cout << "   那就看不出差别了 —— 选测试数据本身就是一门学问。\n";

    return 0;
}