// ============================================================
// 编程练习 1（教材 p86）
// ------------------------------------------------------------
// 题目要求：
//   1. 让用户用整数输入身高（单位：英寸）；
//   2. 把英寸换算成"几英尺几英寸"；
//   3. 用下划线字符指示输入位置（本程序用 ________ 加 \b 退格实现）；
//   4. 换算因子必须用 const 符号常量表示（这里：INCHES_PER_FOOT = 12）。
// 关键点：
//   1 英尺 = 12 英寸，所以"英尺数 = 英寸数 / 12"（整数除法取商），
//   "剩余英寸 = 英寸数 % 12"（取模得余数）——"/" 和 "%" 配对的经典套路。
//   注意第 12、13 行的顺序：先算出英尺并保存，再让 inches 变成余数。
// 预期输出（教材给的例子，输入 170）：
//   Enter your height in inches: ________
//   170（在下划线上输入）
//   Your height is: 14 foots 2 inches.
//   因为 170 / 12 = 14，170 % 12 = 2。
// 编译：g++ -std=c++17 -Wall -Wextra ex1.cpp -o ex1
// ============================================================

#include <iostream>

const int INCHES_PER_FOOT = 12;

int main()
{
    using namespace std;
    cout << "Enter your height in inches: ________\b\b\b\b\b\b\b\b";
    int inches;
    cin >> inches;
    int feet;
    feet = inches / INCHES_PER_FOOT;
    inches = inches % INCHES_PER_FOOT;
    cout << "Your height is: " << feet << " foots " << inches << " inches.";

    return 0;
}
