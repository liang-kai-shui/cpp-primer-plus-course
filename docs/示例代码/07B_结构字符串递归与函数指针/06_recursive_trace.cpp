#include <iostream>
void trace(int level);
int main()
{
    int level = 0;
    if (!(std::cin >> level) || level < 0 || level > 8) {
        std::cerr << "Expected depth 0..8\n";
        return 1;
    }
    trace(level);
}
void trace(int level)
{
    std::cout << "enter " << level << '\n';
    if (level > 0) trace(level - 1);
    std::cout << "leave " << level << '\n';
}
