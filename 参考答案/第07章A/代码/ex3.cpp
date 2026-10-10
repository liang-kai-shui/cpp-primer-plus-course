#include <cmath>
#include <iostream>
int fill_values(double values[], int capacity);
void show_values(const double values[], int count);
void reverse_values(double values[], int count);
int main()
{
    double values[6]{};
    int count = fill_values(values, 6);
    if (count < 0) return 1;
    show_values(values, count);
    reverse_values(values, count);
    show_values(values, count);
    if (count > 2) reverse_values(values + 1, count - 2);
    show_values(values, count);
}
int fill_values(double values[], int capacity)
{
    int count = 0;
    double value = 0;
    while (count < capacity && (std::cin >> value)) {
        if (!std::isfinite(value) || std::abs(value) > 1e6) {
            std::cerr << "Expected finite value in [-1000000,1000000]\n";
            return -1;
        }
        values[count++] = value;
    }
    return count;
}
void show_values(const double values[], int count)
{
    std::cout << "values:";
    for (int i = 0; i < count; ++i) std::cout << ' ' << values[i];
    std::cout << '\n';
}
void reverse_values(double values[], int count)
{
    for (int left = 0; left < count / 2; ++left) {
        int right = count - 1 - left;
        double temporary = values[left];
        values[left] = values[right];
        values[right] = temporary;
    }
}
