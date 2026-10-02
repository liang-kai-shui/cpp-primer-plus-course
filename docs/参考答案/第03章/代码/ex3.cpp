// ============================================================
// 编程练习 3（教材 p86）
// ------------------------------------------------------------
// 题目要求：
//   1. 让用户以"度、分、秒"输入一个纬度；
//   2. 以"度"为单位显示该纬度；
//   3. 1 度 = 60 分，1 分 = 60 秒，以符号常量的方式表示这些值；
//   4. 每个输入值用独立的变量存储。
// 关键点（本题唯一的坑）：避开整数除法。
//   换算要写成 度 + 分/60 + 秒/3600。若 分/60 两边都是 int，
//   会走整数除法直接得到 0，结果就只剩"度"。本程序第 8 行用
//   double(minutes) / 60 和 double(second) / 3600 显式提升为浮点除法。
//   （写成 51.0 / 60 也行，效果一样。）
// 预期输出（教材给的例子，输入 37 51 19）：
//   Enter a latitude in degrees, minutes, and seconds:
//   First, enter the degrees: 37
//   Next, enter the minutes of arc: 51
//   Finally, enter the seconds of arc: 19
//   37 degrees, 51 minutes, 19 seconds = 37.8553 degrees
//   （37 + 51/60 + 19/3600 = 37.85527777...）
//   教材写法用了 fixed << setprecision(4)（需 #include <iomanip>）；
//   本程序没加，靠默认的 6 位有效数字也显示成 37.8553。
// 编译：g++ -std=c++17 -Wall -Wextra ex3.cpp -o ex3
// ============================================================

#include <iostream>

double calculate_degrees(int degree, int minutes, int second);

double calculate_degrees(int degree, int minutes, int second)
{
    double degrees;
    degrees = degree + double(minutes) / 60 + double(second) / 3600;
    return degrees;
}

int main()
{
    using namespace std;
    int degree, minutes, second;

    cout << "Enter a latitude in degrees, minutes, and seconds:";
    cout << "\nFirst, enter the degrees: ";
    cin >> degree;
    cout << "Next, enter the minutes of arc: ";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc: ";
    cin >> second;
    cout << degree << " degrees, " << minutes << " minutes, " << second << " seconds = " << calculate_degrees(degree, minutes, second) << " degrees";

    return 0;
}
