#include <iostream>
void print_chars(char symbol, int count);
int main()
{
    int times = 3;
    print_chars('*', times);
    std::cout << "times=" << times << '\n';
    print_chars('-', 0);
}
void print_chars(char symbol, int count)
{
    for (int i = 0; i < count; ++i) std::cout << symbol;
    std::cout << '\n';
}
