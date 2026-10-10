#include <array>
#include <iostream>
void zero_copy(std::array<int, 3> values);
bool add_five(std::array<int, 3>* values);
void show_values(std::array<int, 3> values);
int main()
{
    std::array<int, 3> values{10, 20, 30};
    zero_copy(values);
    show_values(values);
    add_five(&values);
    show_values(values);
    std::cout << "null accepted=" << add_five(nullptr) << '\n';
}
void zero_copy(std::array<int, 3> values)
{
    values.fill(0);
    std::cout << "copy:";
    show_values(values);
}
bool add_five(std::array<int, 3>* values)
{
    if (values == nullptr) return false;
    for (int i = 0; i < 3; ++i) (*values)[i] += 5;
    return true;
}
void show_values(std::array<int, 3> values)
{
    for (int value : values) std::cout << ' ' << value;
    std::cout << '\n';
}
