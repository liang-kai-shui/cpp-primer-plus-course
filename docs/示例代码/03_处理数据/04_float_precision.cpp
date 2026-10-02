// ============================================================
//  示例 4：浮点数与精度陷阱        ★★ 第二大坑 ★★
//              （对应教材 3.3 p72-75、复习题第 7 题）
// ============================================================
#include <iostream>
#include <iomanip> // setprecision 在这里

int main()
{
    using namespace std;
    double a = 0.1 + 0.2;
    double b = 0.3;
    cout << "a == b  的结果: " << (a == b) << endl;
    cout << "相差多少: " << (a - b) << endl;

    cout << "===== 三种浮点类型的大小 =====\n";
    cout << "float       : " << sizeof(float) << " 字节\n";
    cout << "double      : " << sizeof(double) << " 字节\n";
    cout << "long double : " << sizeof(long double) << " 字节\n";

    cout << "\n===== 经典精度问题：0.1 + 0.2 =====\n";
    float f = 0.1f + 0.2f;
    double d = 0.1 + 0.2;
    cout << "float  0.1f + 0.2f = " << f << "\n";
    cout << "double 0.1  + 0.2  = " << d << "\n";
    cout << "d == 0.3 的结果是: " << (d == 0.3) << "   <- false！\n";
    cout << setprecision(17);
    cout << "用 17 位精度看 double: " << d << "\n";
    cout << "  原因：0.1 在二进制里是无限循环小数，存不下，只能近似。\n";

    cout << "\n【结论】浮点数**永远不要用 == 比较**！要用'差值小于某个极小量'来判断。\n";

    cout << setprecision(6);
    cout << "\n===== 复习题第 3 题那个例子：37度51分19秒 =====\n";
    double lat = 37 + 51.0 / 60 + 19.0 / 3600;
    cout << "默认（6 位有效数字）    : " << lat << "\n";
    cout << "固定 4 位小数           : " << fixed << setprecision(4) << lat << "\n";
    cout << "固定 10 位小数（看真相）: " << setprecision(10) << lat << "\n";
    cout << "  -> 教材 p87 练习 3 要求输出 37.8553，用 setprecision 就能控制\n";
    cout << "  -> 两种写法这次碰巧都是 37.8553，但超过 6 位就露馅了\n";
    cout << fixed << setprecision(6); // 复原，免得影响后面

    cout << "\n===== 浮点常量的两种写法（教材 3.3.1 p72）=====\n";
    cout << "小数写法 3.14  = " << 3.14 << "\n";
    cout << "科学计数法 3.14e2 = " << 3.14e2 << "  (3.14 × 10²)\n";
    cout << "科学计数法 3.14e-2 = " << 3.14e-2 << "  (3.14 × 10⁻²)\n";

    cout << "\n===== long 赋给 float / double（复习题第 7 题）=====\n";
    long big = 123456789L;
    float bf = big;
    double bd = big;
    cout << "long   = " << big << "\n";
    cout << "float  = " << fixed << setprecision(0) << bf << "   <- 有舍入误差\n";
    cout << "double = " << bd << "   <- 通常没问题\n";

    return 0;
}