#include <cstddef>
#include <iostream>

int main()
{
    char ch;
    std::size_t count = 0;
    while ((std::cin >> ch) && ch != '#') ++count;
    std::cout << "non-whitespace characters=" << count << '\n';
}
