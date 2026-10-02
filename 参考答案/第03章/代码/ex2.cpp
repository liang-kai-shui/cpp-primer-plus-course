// ============================================================
// 编程练习 2（教材 p86）
// ------------------------------------------------------------
// 题目要求：
//   1. 以"几英尺几英寸"输入身高，以"磅"输入体重，用 3 个变量存储；
//   2. 报告 BMI（Body Mass Index，体重指数）；
//   3. 身高先换算成英寸（1 英尺 = 12 英寸），再换算成米（1 英寸 = 0.0254 米）；
//   4. 体重从磅换算成千克（1 千克 = 2.2 磅）；
//   5. BMI = 体重(千克) / 身高(米)²；
//   6. 各种换算因子都要用符号常量表示（本题用 const double）。
// 关键点（本题是本章综合题，const、隐式类型提升、浮点运算全用上）：
//   身高的换算链 feet → inches → meters 必须全程走浮点。
//   第 12 行 (feet * FEET_TO_INCH + inches) 里 FEET_TO_INCH 是 12.0（double），
//   所以整个表达式已提升为 double，再乘 0.0254，小数不会被整数运算砍掉。
//   体重也用 double 接收，BMI 自然就是 double。
// 预期输出（参考：1.75 米、70 千克 → BMI ≈ 22.79）：
//   按本程序的输入顺序，输入 5 英尺 9 英寸、154 磅（≈ 1.7526 米、70.0 千克）：
//   Enter your height in feet and inches:
//           feet:5
//           inches:9
//   And enter your weight in pounds:154
//   Your BMI is: 22.7894
// 编译：g++ -std=c++17 -Wall -Wextra ex2.cpp -o ex2
// ============================================================

#include <iostream>

const double INCHES_TO_METER = 0.0254;
const double FEET_TO_INCH = 12.0;
const double KG_TO_POUNDS = 2.2;

double calculate_BMI(int feet, int inches, double weight);

double calculate_BMI(int feet, int inches, double weight)
{
    double weight_kg = weight / KG_TO_POUNDS;
    double height_meter = (feet * FEET_TO_INCH + inches) * INCHES_TO_METER;
    double BMI = weight_kg / (height_meter * height_meter);
    return BMI;
}

int main()
{
    using namespace std;

    cout << "Enter your height in feet and inches:\n";
    cout << "\tfeet:___\b\b\b";
    int feet, inches;
    cin >> feet;

    cout << "\tinches:___\b\b\b";
    cin >> inches;

    cout << "And enter your weight in pounds:___\b\b\b";
    double weight;
    cin >> weight;

    cout << "Your BMI is: " << calculate_BMI(feet, inches, weight) << endl;

    return 0;
}
