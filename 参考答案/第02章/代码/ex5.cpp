// ============================================================
// 教材：《C++ Primer Plus（第 6 版）》第 2 章 开始学习 C++
// 题目：编程练习 5（教材 p53–54）——摄氏温度换算成华氏温度
// ------------------------------------------------------------
// 思路要点：
//   1. 写一个返回类型为 double 的用户定义函数，参数是摄氏温度；
//   2. 转换公式：华氏 = 1.8 × 摄氏 + 32.0；
//   3. main() 里读入摄氏温度，调用该函数并按要求格式化输出。
// 值得注意：
//   转换系数必须写成 1.8（浮点字面量）。如果写成 9 / 5，整数除法
//   会得到 1 而不是 1.8（第 3 章细讲）。
//   返回类型要用 double：若用 int，21℃ → 69.8 会被截断成 69。
//   函数原型写在文件顶部（main() 之前），这也是教材的写法之一。
// ============================================================

#include <iostream>
double Celsius_to_Fahrenheit(double);

double Celsius_to_Fahrenheit(double celsius)
{
    double fahrenheit = 1.8 * celsius + 32;
    return fahrenheit;
}

int main()
{
    using namespace std;
    cout << "Please enter a Celsius value:";
    double celsius;
    cin >> celsius;
    cout << celsius << " degrees Celsius is " << Celsius_to_Fahrenheit(celsius) << " degrees Fahrenheit." << endl;
    return 0;
}