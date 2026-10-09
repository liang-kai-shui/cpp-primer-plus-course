#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::string filename;
    if (!std::getline(std::cin, filename)) {
        std::cerr << "No file name\n";
        return 1;
    }
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Cannot open file\n";
        return 1;
    }
    char ch;
    std::size_t count = 0;
    while (in.get(ch)) ++count;
    if (in.bad() || !in.eof()) {
        std::cerr << "Read error\n";
        return 1;
    }
    std::cout << "characters=" << count << '\n';
}
