#include <iostream>
const double* first_value(const double values[], int count);
const double* last_value(const double values[], int count);
using Selector = const double* (*)(const double*, int);
int main()
{
    double values[]{10, 20, 30};
    Selector selectors[]{first_value, last_value};
    for (Selector select : selectors) {
        const double* result = select(values, 3);
        if (result != nullptr) std::cout << "selected=" << *result << '\n';
    }
    auto table = &selectors; // 指向整个函数指针数组，只作补充阅读。
    std::cout << "via table=" << *(*table)[1](values, 3) << '\n';
    std::cout << "empty is null=" << (first_value(values, 0) == nullptr) << '\n';
}
const double* first_value(const double values[], int count)
{
    return count > 0 ? values : nullptr;
}
const double* last_value(const double values[], int count)
{
    return count > 0 ? values + count - 1 : nullptr;
}
