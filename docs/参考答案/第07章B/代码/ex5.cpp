#include <cstddef>
#include <iostream>
#include <string>
std::string make_label(std::string name);
std::size_t count_spaces(std::string text);
int main()
{
    std::string name;
    if (!std::getline(std::cin, name)) {
        std::cerr << "Expected a name line\n";
        return 1;
    }
    std::string label = make_label(name);
    std::cout << "original=" << name << '\n';
    std::cout << "label=" << label << " spaces=" << count_spaces(name) << '\n';
}
std::string make_label(std::string name)
{
    if (name.empty()) return "[anonymous]";
    for (std::size_t i = 0; i < name.size(); ++i) {
        if (name[i] == ' ') name[i] = '_';
    }
    return '[' + name + ']';
}
std::size_t count_spaces(std::string text)
{
    std::size_t count = 0;
    for (char ch : text) {
        if (ch == ' ') ++count;
    }
    return count;
}
