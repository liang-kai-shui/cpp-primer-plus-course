#include <iostream>
int replace_char(char* text, char old_char, char new_char);
int main()
{
    char text[201]{};
    char old_char = 0, new_char = 0;
    if (!std::cin.getline(text, 201)) {
        std::cerr << "Expected a text line of at most 200 bytes\n";
        return 1;
    }
    if (!(std::cin >> old_char >> new_char)) {
        std::cerr << "Expected two non-whitespace characters\n";
        return 1;
    }
    int count = replace_char(text, old_char, new_char);
    std::cout << "count=" << count << " text=" << text << '\n';
}
int replace_char(char* text, char old_char, char new_char)
{
    int count = 0;
    while (*text != '\0') {
        if (*text == old_char) {
            *text = new_char;
            ++count;
        }
        ++text;
    }
    return count;
}
