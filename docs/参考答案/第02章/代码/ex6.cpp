// ============================================================
// 教材：《C++ Primer Plus（第 6 版）》第 2 章 开始学习 C++
// 题目：编程练习 6（教材 p53–54）——光年换算成天文单位（1 光年 = 63240 AU）
// ------------------------------------------------------------
// 思路要点：
//   1. 写一个以光年值为参数、返回对应天文单位值的用户定义函数（double）；
//   2. main() 里读入光年值，调用该函数并按题目要求的格式输出。
// 值得注意：
//   可以用 4.2 × 63240 = 265608 这组数字验证结果对不对；
//   return 语句外面的那对括号是多余的，去掉不影响结果；
//   输出末尾没有换行符（\n 或 endl），结果会紧贴命令行提示符。
// ============================================================

#include <iostream>

double light_to_AU(double);

double light_to_AU(double distance)
{
    return (distance * 63240);
}

int main()
{
    using namespace std;
    double distance;
    cout << "Enter the number of light years:";
    cin >> distance;
    cout << distance << " light years = " << light_to_AU(distance) << " astronomical units.";

    return 0;
}