#include <cmath>
#include <iostream>
double harmonic_mean(double first, double second);
int main()
{
    double first = 0, second = 0;
    while (std::cin >> first) {
        if (!(std::cin >> second)) {
            std::cerr << "Expected a complete pair\n";
            return 1;
        }
        if (first == 0 || second == 0) break;
        if (!std::isfinite(first) || !std::isfinite(second) || first < 0 || second < 0
            || first > 1e6 || second > 1e6) {
            std::cerr << "Expected positive finite values <= 1000000\n";
            return 1;
        }
        std::cout << "mean=" << harmonic_mean(first, second) << '\n';
    }
}
double harmonic_mean(double first, double second)
{
    return 2.0 * first * second / (first + second);
}
