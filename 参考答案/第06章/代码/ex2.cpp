#include <array>
#include <cmath>
#include <cstddef>
#include <iostream>

int main()
{
    std::array<double, 10> data{};
    std::size_t count = 0;
    double value, total = 0.0;
    while (count < data.size() && (std::cin >> value)) {
        if (value < 0 || !std::isfinite(value)) {
            std::cerr << "Expected a finite nonnegative number\n";
            return 1;
        }
        data[count++] = value;
        total += value;
    }
    if (std::cin.bad()) {
        std::cerr << "Read error\n";
        return 1;
    }
    std::cout << "count=" << count << '\n';
    if (count == 0) {
        std::cout << "No data\n";
        return 0;
    }
    double average = total / count;
    std::size_t above = 0;
    for (std::size_t i = 0; i < count; ++i) {
        if (data[i] > average) ++above;
    }
    std::cout << "average=" << average << " above=" << above << '\n';
}
