#include <iostream>
long long sum_range(const int* begin, const int* end);
int main()
{
    int values[]{1, 2, 3, 4, 5};
    std::cout << "all=" << sum_range(values, values + 5) << '\n';
    std::cout << "first three=" << sum_range(values, values + 3) << '\n';
    std::cout << "middle=" << sum_range(values + 1, values + 4) << '\n';
    std::cout << "empty=" << sum_range(values + 2, values + 2) << '\n';
}
long long sum_range(const int* begin, const int* end)
{
    long long total = 0;
    for (const int* current = begin; current != end; ++current) total += *current;
    return total;
}
