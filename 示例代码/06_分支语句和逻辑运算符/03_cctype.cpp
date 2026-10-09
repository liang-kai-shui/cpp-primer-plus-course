#include <cctype>
#include <cstddef>
#include <iostream>

int main()
{
    std::size_t letters = 0, digits = 0, spaces = 0, others = 0;
    char ch;
    while (std::cin.get(ch)) {
        unsigned char byte = static_cast<unsigned char>(ch);
        if (std::isalpha(byte)) {
            ++letters;
            std::cout.put(static_cast<char>(std::toupper(byte)));
        } else if (std::isdigit(byte)) {
            ++digits;
        } else if (std::isspace(byte)) {
            ++spaces;
        } else {
            ++others;
        }
    }
    std::cout << "\nletters=" << letters << " digits=" << digits
              << " spaces=" << spaces << " others=" << others << '\n';
}
