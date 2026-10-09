#include <iostream>

int main()
{
    int checks = 0;
    int bodies = 0;
    for (int i = 0; (++checks, i < 3); ++i) {
        std::cout << "body i=" << i << '\n';
        ++bodies;
    }
    // 逗号左边计数，右边才是本次条件的真假。
    std::cout << "checks=" << checks << " bodies=" << bodies << '\n';
}
