#include <cctype>
#include <iostream>

int main()
{
    char ch;
    while (std::cin.get(ch) && ch != '@') {
        unsigned char byte = static_cast<unsigned char>(ch);
        if (std::isdigit(byte)) continue;
        if (std::islower(byte)) ch = static_cast<char>(std::toupper(byte));
        else if (std::isupper(byte)) ch = static_cast<char>(std::tolower(byte));
        std::cout.put(ch);
    }
}
