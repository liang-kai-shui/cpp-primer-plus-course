#include <array>
#include <iomanip>
#include <iostream>

int main()
{
    int n;
    if (!(std::cin >> n) || n < 0 || n > 100) {
        std::cerr << "n must be 0..100\n";
        return 1;
    }
    std::array<long double, 101> facts{};
    facts[0] = 1;
    for (int i = 1; i <= n; ++i) facts[i] = facts[i - 1] * i;
    std::cout << std::setprecision(10);
    for (int i = 0; i <= n; ++i) std::cout << i << "!=" << facts[i] << '\n';
}
