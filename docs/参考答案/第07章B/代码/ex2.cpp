#include <cmath>
#include <iostream>
struct Expenses { double values[4]; };
bool fill_expenses(Expenses* expenses);
void show_expenses(const Expenses* expenses);
int main()
{
    Expenses expenses{};
    if (!fill_expenses(&expenses)) {
        std::cerr << "Expected four finite expenses 0..1000000\n";
        return 1;
    }
    show_expenses(&expenses);
}
bool fill_expenses(Expenses* expenses)
{
    if (expenses == nullptr) return false;
    for (int i = 0; i < 4; ++i) {
        double value = 0;
        if (!(std::cin >> value) || !std::isfinite(value) || value < 0 || value > 1e6) return false;
        expenses->values[i] = value;
    }
    return true;
}
void show_expenses(const Expenses* expenses)
{
    if (expenses == nullptr) return;
    const char* names[]{"Spring", "Summer", "Fall", "Winter"};
    double total = 0;
    for (int i = 0; i < 4; ++i) {
        std::cout << names[i] << '=' << expenses->values[i] << '\n';
        total += expenses->values[i];
    }
    std::cout << "total=" << total << '\n';
}
