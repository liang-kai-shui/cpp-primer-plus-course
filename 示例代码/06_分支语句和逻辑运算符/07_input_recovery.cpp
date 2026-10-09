#include <iostream>
#include <limits>

int main()
{
    int number;
    while (true) {
        std::cout << "Integer 0..100 (EOF to stop): ";
        if (std::cin >> number) {
            if (number < 0 || number > 100) {
                std::cout << "Out of range\n";
                continue;
            }
            std::cout << "accepted=" << number << '\n';
        } else if (std::cin.eof()) {
            std::cout << "End of input\n";
            break;
        } else if (std::cin.bad()) {
            std::cerr << "Read error\n";
            return 1;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Not an integer; discarded this line\n";
        }
    }
}
