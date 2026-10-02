// ============================================================
// 编程练习 4（教材 p87）⭐ 本章最核心的一题
// ------------------------------------------------------------
// 题目要求：
//   1. 让用户以整数方式输入秒数，用 long 或 long long 变量存储；
//   2. 以"天、小时、分钟、秒"的方式显示这段时间；
//   3. 用符号常量表示每天多少小时、每小时多少分钟、每分钟多少秒
//      （即 24、60、60，由此推出 86400 秒/天、3600 秒/小时）。
// 关键点：纯靠 "/" 和 "%" 配对，每一层都是"先除得商、再取模得余数"。
//     days    = 总秒数 / 86400;   总秒数 = 总秒数 % 86400;
//     hours   = 总秒数 / 3600;    总秒数 = 总秒数 % 3600;
//     minutes = 总秒数 / 60;      秒数   = 总秒数 % 60;
//   本程序把 86400、3600、60 直接写成了字面量（没有用 const 符号常量）；
//   按教材要求应改成 const long long SEC_PER_DAY = 24 * 60 * 60; 等。
//   变量用 long long：输入 31600000 虽然装得进 int，但秒数很容易越界。
// 预期输出（教材给的例子，输入 31600000）：
//   Enter the number of seconds: 31600000
//   31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds
//   验证：365*86400 + 17*3600 + 46*60 + 40 = 31600000 ✓
// 编译：g++ -std=c++17 -Wall -Wextra ex4.cpp -o ex4
// ============================================================

#include <iostream>

void calculate_seconds(long long total_seconds);

void calculate_seconds(long long total_seconds)
{
    std::cout << total_seconds;
    int seconds, days, hours, minutes;
    days = total_seconds / 86400;
    total_seconds = total_seconds % 86400;
    hours = total_seconds / 3600;
    total_seconds = total_seconds % 3600;
    minutes = total_seconds / 60;
    seconds = total_seconds % 60;
    std::cout << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";
}

int main()
{
    using namespace std;
    long long seconds;
    cout << "Enter the number of seconds: ";
    cin >> seconds;
    calculate_seconds(seconds);
    return 0;
}
