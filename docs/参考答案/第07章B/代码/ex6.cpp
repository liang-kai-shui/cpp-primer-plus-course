#include <cmath>
#include <iostream>
using Operation = double (*)(double, double);
double add(double first, double second);
double subtract(double first, double second);
double multiply(double first, double second);
double calculate(double first, double second, Operation operation);
int main()
{
    Operation operations[]{add, subtract, multiply};
    const char* names[]{"add", "subtract", "multiply"};
    double first = 0, second = 0;
    while (std::cin >> first) {
        if (!(std::cin >> second)) {
            std::cerr << "Expected a complete pair\n";
            return 1;
        }
        if (!std::isfinite(first) || !std::isfinite(second) || std::abs(first) > 1000 || std::abs(second) > 1000) {
            std::cerr << "Expected finite values in [-1000,1000]\n";
            return 1;
        }
        for (int i = 0; i < 3; ++i) {
            std::cout << names[i] << '=' << calculate(first, second, operations[i]) << '\n';
        }
    }
}
double add(double first, double second) { return first + second; }
double subtract(double first, double second) { return first - second; }
double multiply(double first, double second) { return first * second; }
double calculate(double first, double second, Operation operation)
{
    return operation(first, second); // operations中的三个元素均已初始化为有效函数。
}
