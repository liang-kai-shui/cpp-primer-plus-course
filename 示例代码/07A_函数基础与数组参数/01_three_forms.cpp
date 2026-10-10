#include <iostream>
double cube(double value); // 原型：说明输入和返回值的类型。
int main()
{
    std::cout << "Before call\n";
    double answer = cube(3.0); // 调用：接住结果。
    std::cout << "answer=" << answer << '\n';
}
double cube(double value) // 定义：实现具体计算。
{
    std::cout << "Inside cube\n";
    return value * value * value;
}
