#include <cmath>
#include <iostream>
double* fill_range(double* begin, double* end);
void show_range(const double* begin, const double* end);
double sum_range(const double* begin, const double* end);
int main()
{
    double values[5]{};
    double* used_end = fill_range(values, values + 5);
    if (used_end == nullptr) return 1;
    show_range(values, used_end);
    std::cout << "count=" << used_end - values << " total=" << sum_range(values, used_end) << '\n';
}
double* fill_range(double* begin, double* end)
{
    double* current = begin;
    double value = 0;
    while (current != end && (std::cin >> value)) {
        if (!std::isfinite(value) || std::abs(value) > 1e6) {
            std::cerr << "Expected finite value in [-1000000,1000000]\n";
            return nullptr;
        }
        *current = value;
        ++current;
    }
    return current; // 已填区间末尾的下一个位置，不是最后元素。
}
void show_range(const double* begin, const double* end)
{
    std::cout << "values:";
    for (const double* current = begin; current != end; ++current) std::cout << ' ' << *current;
    std::cout << '\n';
}
double sum_range(const double* begin, const double* end)
{
    double total = 0;
    for (const double* current = begin; current != end; ++current) total += *current;
    return total;
}
