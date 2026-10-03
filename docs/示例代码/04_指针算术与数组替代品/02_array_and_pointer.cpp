#include <iostream>

int main()
{
    int values[4]{10, 20, 30, 40};
    int* p = values;
    std::cout << "sizeof(values) = " << sizeof(values) << '\n';
    std::cout << "sizeof(p) = " << sizeof(p) << '\n';
    std::cout << "values[2] = " << values[2]
              << ", *(values+2) = " << *(values + 2) << '\n';

    // 两个地址的数字起点可能相同，但指针类型与 +1 的跨度不同。
    int (*whole)[4] = &values;
    std::cout << "&values = " << static_cast<const void*>(whole) << '\n';
    std::cout << "&values + 1 = " << static_cast<const void*>(whole + 1) << '\n';
    std::cout << "&values[0] + 1 = "
              << static_cast<const void*>(&values[0] + 1) << '\n';
}
