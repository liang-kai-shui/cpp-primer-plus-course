#include <cmath>
#include <iostream>
int fill_values(double data[], int capacity);
void show_values(const double data[], int count);
void scale_values(double data[], int count, double factor);
int main()
{
    double data[5]{};
    int count = fill_values(data, 5);
    show_values(data, count);
    scale_values(data, count, 1.1);
    show_values(data, count);
}
int fill_values(double data[], int capacity)
{
    int count = 0;
    double value = 0;
    while (count < capacity && (std::cin >> value)) {
        if (value < 0) break; // 本示例约定负数结束。
        if (!std::isfinite(value) || value > 1e6) break;
        data[count] = value;
        ++count;
    }
    return count;
}
void show_values(const double data[], int count)
{
    std::cout << "count=" << count << " values:";
    for (int i = 0; i < count; ++i) std::cout << ' ' << data[i];
    std::cout << '\n';
}
void scale_values(double data[], int count, double factor)
{
    for (int i = 0; i < count; ++i) data[i] *= factor;
}
