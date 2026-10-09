#include <iostream>

int main()
{
    int a, b;
    if (!(std::cin >> a >> b)) {
        std::cerr << "Expected two integers\n";
        return 1;
    }
    int larger = a > b ? a : b;
    std::cout << "larger=" << larger << '\n';
}
