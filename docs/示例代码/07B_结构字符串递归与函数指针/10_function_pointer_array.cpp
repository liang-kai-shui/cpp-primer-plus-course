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
    for (int i = 0; i < 3; ++i) {
        std::cout << names[i] << '=' << calculate(2, 3, operations[i]) << '\n';
    }
}
double add(double first, double second) { return first + second; }
double subtract(double first, double second) { return first - second; }
double multiply(double first, double second) { return first * second; }
double calculate(double first, double second, Operation operation)
{
    return operation(first, second);
}
