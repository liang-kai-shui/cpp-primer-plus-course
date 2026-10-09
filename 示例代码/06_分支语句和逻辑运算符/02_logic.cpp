#include <iostream>

int main()
{
    int calls = 0;
    bool result = false && (++calls > 0);
    std::cout << std::boolalpha << "false AND: " << result << " calls=" << calls << '\n';
    result = true && (++calls > 0);
    std::cout << "true AND: " << result << " calls=" << calls << '\n';
    result = true || (++calls > 0);
    std::cout << "true OR: " << result << " calls=" << calls << '\n';
    result = false || (++calls > 0);
    std::cout << "false OR: " << result << " calls=" << calls << '\n';
    int denominator = 0;
    result = denominator != 0 && 12 / denominator > 2;
    std::cout << "safe division condition=" << result << '\n';
}
