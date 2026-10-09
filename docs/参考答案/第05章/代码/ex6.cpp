#include <iostream>

int main()
{
    int n;
    if (!(std::cin >> n) || n < 1 || n > 30) {
        std::cerr << "n must be 1..30\n";
        return 1;
    }
    for (int row = 1; row <= n; ++row) {
        for (int dot = 0; dot < n - row; ++dot) std::cout << '.';
        for (int star = 0; star < row; ++star) std::cout << '*';
        std::cout << '\n';
    }
}
