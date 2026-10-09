#include <cmath>
#include <iomanip>
#include <iostream>

int main()
{
    double points;
    while ((std::cin >> points) && points >= 0) {
        if (!std::isfinite(points)) {
            std::cerr << "Expected finite points\n";
            return 1;
        }
        double deduction = 0.0;
        if (points > 35000) {
            deduction = 10000 * 0.10 + 20000 * 0.15 + (points - 35000) * 0.20;
        } else if (points > 15000) {
            deduction = 10000 * 0.10 + (points - 15000) * 0.15;
        } else if (points > 5000) {
            deduction = (points - 5000) * 0.10;
        }
        std::cout << std::fixed << std::setprecision(2) << "deduction=" << deduction << '\n';
    }
}
