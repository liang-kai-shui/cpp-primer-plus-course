#include <iostream>
double square(double value);
double half(double value);
double apply(double value, double (*operation)(double));
int main()
{
    double (*operation)(double) = square;
    std::cout << "direct=" << operation(4) << '\n';
    std::cout << "explicit=" << (*operation)(4) << '\n';
    operation = half;
    std::cout << "after change=" << operation(4) << '\n';
    std::cout << "apply square=" << apply(3, square) << '\n';
    std::cout << "apply half=" << apply(3, half) << '\n';
}
double square(double value) { return value * value; }
double half(double value) { return value / 2.0; }
double apply(double value, double (*operation)(double))
{
    return operation(value); // 前提：operation指向类型匹配的有效函数。
}
