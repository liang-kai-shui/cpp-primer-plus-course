#include <cstddef>
#include <iostream>
std::size_t count_char(const char* text, char wanted);
int main()
{
    const char* text = "banana";
    std::cout << "a count=" << count_char(text, 'a') << '\n';
    std::cout << "original=" << text << '\n';
    std::cout << "empty=" << count_char("", 'a') << '\n';
}
std::size_t count_char(const char* text, char wanted)
{
    std::size_t count = 0;
    while (*text != '\0') {
        if (*text == wanted) ++count;
        ++text;
    }
    return count;
}
