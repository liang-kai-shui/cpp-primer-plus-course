#include <iostream>
unsigned long long factorial(int number);
int main()
{
    int number = 0;
    if (!(std::cin >> number) || number < 0 || number > 20) {
        std::cerr << "Expected integer 0..20\n";
        return 1;
    }
    std::cout << "factorial=" << factorial(number) << '\n';
}
unsigned long long factorial(int number)
{
    if (number == 0) return 1;
    return static_cast<unsigned long long>(number) * factorial(number - 1);
}
