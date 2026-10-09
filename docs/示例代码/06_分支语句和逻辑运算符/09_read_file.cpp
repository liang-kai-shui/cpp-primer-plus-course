#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::string filename;
    std::cout << "File name: ";
    if (!std::getline(std::cin, filename)) {
        std::cerr << "No file name\n";
        return 1;
    }
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Cannot open file\n";
        return 1;
    }
    double value, total = 0.0;
    std::size_t count = 0;
    while (in >> value) {
        if (!std::isfinite(value)) {
            std::cerr << "Non-finite number\n";
            return 1;
        }
        total += value;
        ++count;
    }
    if (in.bad()) {
        std::cerr << "Read error\n";
        return 1;
    }
    if (!in.eof()) {
        std::cerr << "Non-numeric data\n";
        return 1;
    }
    std::cout << "count=" << count << " total=" << total << '\n';
    if (count == 0) std::cout << "No data\n";
    else std::cout << "average=" << total / count << '\n';
}
