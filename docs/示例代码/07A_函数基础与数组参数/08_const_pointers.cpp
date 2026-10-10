#include <iostream>
int main()
{
    int first = 3, second = 7;
    const int* reader = &first; // 可以换地址，不能经reader写入。
    first = 4;
    std::cout << "reader=" << *reader << '\n';
    reader = &second;
    std::cout << "reader after move=" << *reader << '\n';
    int* const writer = &first; // 不能换地址，可以经writer写入。
    *writer = 9;
    std::cout << "first=" << first << '\n';
    const int* const fixed_reader = &second;
    std::cout << "fixed reader=" << *fixed_reader << '\n';
}
