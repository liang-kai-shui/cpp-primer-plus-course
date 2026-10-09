#include <cstddef>
#include <iostream>
#include <string>

int main()
{
    std::string word;
    std::size_t count = 0;
    while ((std::cin >> word) && word != "done") ++count;
    std::cout << "words=" << count << '\n';
}
