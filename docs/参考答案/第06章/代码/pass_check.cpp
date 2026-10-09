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
    int value;
    long long total = 0;
    std::size_t count = 0;
    while (in >> value) {
        if (value < 0) continue;
        ++count;
        total += value;
    }
    if (in.bad() || !in.eof()) {
        std::cerr << "Invalid data or read error\n";
        return 1;
    }
    std::cout << "count=" << count << " total=" << total << '\n';
}
