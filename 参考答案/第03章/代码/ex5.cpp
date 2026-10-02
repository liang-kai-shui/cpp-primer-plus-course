// ============================================================
// 编程练习 5（教材 p87）
// ------------------------------------------------------------
// 题目要求：
//   1. 让用户输入全球当前人口和美国（或其他国家）当前人口；
//   2. 用 long long 变量存储这两个值；
//   3. 显示该国人口占全球人口的百分比。
// 关键点：这题藏着一个大坑——整数除法。
//     double pct = us / world * 100;          // ❌ 两个整数相除先得 0，结果永远是 0
//     double pct = us / (double)world * 100;  // ✅ 先把一个操作数转成 double
//     double pct = (double)us / world * 100;  // ✅ 也行
//   本程序第 8 行用的是 double(us_population) / total_population * 100，
//   即"先把被除数提升为 double"，同一个道理。
//   这就是复习题第 8、9 题讲的东西，正好用上。
// 预期输出（教材给的例子）：
//   Enter the world's population: 6898758899
//   Enter the population of the US: 310783781
//   The population of the US is 4.50492% of the world population.
//   （310783781 / 6898758899 * 100 = 4.5049230673...，默认 setprecision(6) 显示 4.50492）
// 编译：g++ -std=c++17 -Wall -Wextra ex5.cpp -o ex5
// ============================================================

#include <iostream>

double usPopulationPercent(long long total_population, long long us_population);

double usPopulationPercent(long long total_population, long long us_population)
{
    double percent;
    percent = double(us_population) / total_population * 100;

    return percent;
}

int main()
{
    using namespace std;
    long long total_population, us_population;
    cout << "Enter the world's population: ";
    cin >> total_population;
    cout << "Enter the population of the US: ";
    cin >> us_population;
    cout << "The population of the US is " << usPopulationPercent(total_population, us_population) << "% of the world population.";

    return 0;
}
