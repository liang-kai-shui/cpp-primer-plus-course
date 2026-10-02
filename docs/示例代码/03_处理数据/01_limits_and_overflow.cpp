// ============================================================
//  示例 1：整型的范围与溢出          ★ C++ 不救你 ★
//              （对应教材 3.1.3 p56-62、复习题第 3 题）
// ============================================================
#include <iostream>
#include <climits>          // 这里定义了 INT_MAX 等常量
#include <iomanip>          // setw 用来对齐输出

int main()
{
    using namespace std;

    cout << left << setw(15) << "类型" << setw(8) << "字节" << "取值范围\n";
    cout << string(62, '-') << "\n";
    cout << left << setw(15) << "short"        << setw(8) << sizeof(short)        << SHRT_MIN << " ~ " << SHRT_MAX << "\n";
    cout << left << setw(15) << "int"          << setw(8) << sizeof(int)          << INT_MIN << " ~ " << INT_MAX << "\n";
    cout << left << setw(15) << "long"         << setw(8) << sizeof(long)         << LONG_MIN << " ~ " << LONG_MAX << "\n";
    cout << left << setw(15) << "long long"    << setw(8) << sizeof(long long)    << LLONG_MIN << " ~ " << LLONG_MAX << "\n";
    cout << left << setw(15) << "unsigned int" << setw(8) << sizeof(unsigned int) << 0 << " ~ " << UINT_MAX << "\n";
    cout << endl;
    cout << "【注意】在 Windows/MinGW 上 long 也是 4 字节，和 int 一样！\n";
    cout << "        教材说 long 至少 32 位；要存大数请用 long long（8 字节）。\n";
    cout << endl;

    // ---------- 溢出实验 ----------
    short s = SHRT_MAX;             // short 的最大值
    cout << "short 最大值        : " << s << endl;
    s = s + 1;                      // 再加 1 会怎样？
    cout << "加 1 之后           : " << s << "   <- 翻到负数去了（溢出）" << endl;

    unsigned short us = 0;
    us = us - 1;                    // 无符号的 0 减 1
    cout << "unsigned short 0-1  : " << us << "   <- 绕回最大值" << endl;

    cout << endl;
    cout << "【结论】C++ 编译器**不会**检查整型溢出，教材 3.6 复习题第 3 题就是在问这个。" << endl;
    cout << "        你只能靠自己选对类型。" << endl;

    return 0;
}