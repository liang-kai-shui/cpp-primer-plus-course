#include <iostream>

int main()
{
    int score;
    if (!(std::cin >> score)) {
        std::cerr << "Expected an integer\n";
        return 1;
    }
    if (score < 0 || score > 100) {
        std::cerr << "Score must be 0..100\n";
        return 1;
    }
    if (score >= 90) {
        std::cout << "A\n";
    } else if (score >= 80) {
        std::cout << "B\n";
    } else if (score >= 60) {
        std::cout << "C\n";
    } else {
        std::cout << "Not passed\n";
    }
}
