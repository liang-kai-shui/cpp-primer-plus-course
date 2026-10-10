#include <iostream>
long long sum_values(const int* data, int count);
int main()
{
    int data[]{2, 4, 6, 8};
    std::cout << "array bytes=" << sizeof data << '\n';
    long long all = sum_values(data, 4);
    long long first_two = sum_values(data, 2);
    long long last_two = sum_values(data + 2, 2);
    long long empty = sum_values(data, 0);
    std::cout << "all=" << all << '\n';
    std::cout << "first two=" << first_two << '\n';
    std::cout << "last two=" << last_two << '\n';
    std::cout << "empty=" << empty << '\n';
}
long long sum_values(const int* data, int count)
{
    std::cout << "pointer bytes=" << sizeof data << '\n';
    long long total = 0;
    for (int i = 0; i < count; ++i) total += data[i];
    return total;
}
