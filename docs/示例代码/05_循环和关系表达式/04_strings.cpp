#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>

int main()
{
    char a[] = "hi";
    char b[] = "hi";
    const char* pa = a;
    const char* pb = b;
    std::cout << std::boolalpha << "same address=" << (pa == pb)
              << " same text=" << (std::strcmp(a, b) == 0) << '\n';
    std::cout << "string ordering=" << (std::string("10") < "2") << '\n';

    std::string word;
    std::cout << "ASCII line: ";
    if (!std::getline(std::cin, word)) {
        std::cerr << "No line\n";
        return 1;
    }
    for (std::size_t i = word.size(); i > 0; --i) {
        std::cout << word[i - 1];
    }
    std::cout << '\n';
}
