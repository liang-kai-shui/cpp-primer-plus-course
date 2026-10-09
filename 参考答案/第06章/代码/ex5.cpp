#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>

int main()
{
    std::size_t vowels = 0, consonants = 0, others = 0;
    std::string word;
    while ((std::cin >> word) && word != "q") {
        unsigned char first = static_cast<unsigned char>(word[0]);
        if (!std::isalpha(first)) {
            ++others;
            continue;
        }
        char lower = static_cast<char>(std::tolower(first));
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') ++vowels;
        else ++consonants;
    }
    std::cout << "vowels=" << vowels << " consonants=" << consonants
              << " others=" << others << '\n';
}
