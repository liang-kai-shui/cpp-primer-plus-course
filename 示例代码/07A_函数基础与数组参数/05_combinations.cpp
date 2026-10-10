#include <iomanip>
#include <iostream>
long double combinations(int total, int chosen);
int main()
{
    int total = 0, chosen = 0;
    if (!(std::cin >> total >> chosen) || total < 0 || total > 100 || chosen < 0 || chosen > total) {
        std::cerr << "Expected 0 <= chosen <= total <= 100\n";
        return 1;
    }
    std::cout << std::setprecision(12) << "combinations=" << combinations(total, chosen) << '\n';
}
long double combinations(int total, int chosen)
{
    long double result = 1.0L;
    for (int i = 1; i <= chosen; ++i) {
        result *= static_cast<long double>(total - i + 1) / i;
    }
    return result;
}
