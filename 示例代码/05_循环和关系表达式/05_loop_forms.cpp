#include <iostream>

int main()
{
    std::cout << "for: ";
    for (int n = 3; n > 0; --n) std::cout << n << ' ';
    std::cout << "\nwhile: ";
    int n = 3;
    while (n > 0) {
        std::cout << n << ' ';
        --n;
    }
    std::cout << "\nzero while: ";
    n = 0;
    while (n > 0) {
        std::cout << n << ' ';
        --n;
    }
    std::cout << "\nzero do: ";
    do {
        std::cout << n << ' ';
        --n;
    } while (n > 0);
    std::cout << '\n';
}
