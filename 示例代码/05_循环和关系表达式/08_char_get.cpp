#include <cstddef>
#include <iostream>

int main()
{
    char ch;
    std::size_t count = 0;
    while (std::cin.get(ch) && ch != '#') ++count;
    std::cout << "characters including whitespace=" << count << '\n';
}
