#include <cstring>
#include <iostream>
#include <string>

int main()
{
    const char* message = "hello";
    char word[] = "hello";
    word[0] = 'H';

    std::cout << "message + 1: " << message + 1 << '\n';
    std::cout << "word: " << word << '\n';
    std::cout << "strlen(word) = " << std::strlen(word) << '\n';
    std::cout << "sizeof(word) = " << sizeof(word) << '\n';

    std::string safer = "hello";
    safer[0] = 'H';
    std::cout << "std::string: " << safer << ", size = " << safer.size() << '\n';
}
