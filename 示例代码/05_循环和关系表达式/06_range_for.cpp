#include <iostream>

int main()
{
    int scores[]{70, 80, 90};
    for (int score : scores) {
        score += 5;
        std::cout << "copy=" << score << '\n';
    }
    std::cout << "original=" << scores[0] << '\n';
    for (int& score : scores) score += 5;
    std::cout << "after reference: ";
    for (int score : scores) std::cout << score << ' ';
    std::cout << '\n';
}
