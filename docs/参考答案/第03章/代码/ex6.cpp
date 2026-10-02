// ============================================================
// 编程练习 6（教材 p87）
// ------------------------------------------------------------
// 题目要求：
//   1. 让用户输入驱车里程（英里）和使用汽油量（加仑）；
//   2. 指出汽车耗油量——每一加仑跑多少英里（美国风格）；
//   3. 也可以改用公里和升，给出欧洲风格的结果——
//      每 100 公里的耗油量（升）。
// 关键点：两种风格互为倒数。
//   美国风格 = 距离 / 燃料        （每加仑跑多少英里）
//   欧洲风格 = 燃料 / 距离 × 100  （每 100 公里烧多少升）
// 本程序采用的是"公里 + 升 → 欧洲风格"这条路：
//   第 11 行 liter_per_100kilo = liter / mileage * 100;
//   因为 mileage 和 liter 都声明成 double，所以 "/" 是浮点除法，
//   不会踩到练习 5 那个整数除法的坑。（若把它们写成 int，这题就全错。）
// 预期输出（示例输入：里程 160.9 公里、耗油 12.4 升）：
//   Enter your car's mileage in kilometer:160.9
//   Enter the liter your car has used:12.4
//   Your car is: 7.70665 liter per 100kilometers
//   （12.4 / 160.9 * 100 = 7.7066...）
//   想验证两种风格的倒数关系，可以拿这组数比一比：
//   12.4 L/100km 折合约 18.97 mpg（美国风格）。
// 编译：g++ -std=c++17 -Wall -Wextra ex6.cpp -o ex6
// ============================================================

#include <iostream>

int main()
{
    using namespace std;
    double mileage, liter, liter_per_100kilo;
    cout << "Enter your car's mileage in kilometer:";
    cin >> mileage;
    cout << "Enter the liter your car has used:";
    cin >> liter;
    liter_per_100kilo = liter / mileage * 100;
    cout << "Your car is: " << liter_per_100kilo << " liter per 100kilometers";
    return 0;
}
