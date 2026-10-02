// ============================================================
// 教材：《C++ Primer Plus（第 6 版）》第 2 章 开始学习 C++
// 题目：编程练习 7（教材 p53–54）——把小时和分钟传给一个 void 函数并显示
// ------------------------------------------------------------
// 思路要点：
//   1. 函数返回类型是 void（不返回值），接收两个 int 参数；
//   2. main() 里分别读入小时数和分钟数，再把它们传给该函数显示。
// 值得注意：
//   本题是“用户定义的函数”训练的收尾：有原型、有参数、无返回值。
//   输出 "Time: 9:28" 之后不换行，与教材示例一致；
//   函数体开头多了一个空行，不影响行为。
// ============================================================

#include <iostream>

void show_time(int hours, int minutes);

void show_time(int hours, int minutes)
{

    std::cout << "Time: " << hours << ":" << minutes;
}

int main()
{
    using namespace std;
    int hours, minutes;
    cout << "Enter the number of hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    show_time(hours, minutes);

    return 0;
}