#include <iostream>

int main()
{
    double* value = new double{2.5};
    *value *= 2;
    std::cout << *value << '\n';
    delete value;
    value = nullptr;
}
