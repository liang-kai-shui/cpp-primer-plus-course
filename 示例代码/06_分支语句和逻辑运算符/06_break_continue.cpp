#include <iostream>

int main()
{
    int number;
    long long sum = 0;
    while (std::cin >> number) {
        if (number == 0) break;
        if (number < 0) continue;
        sum += number;
    }
    std::cout << "sum=" << sum << '\n';
}
