#include <iomanip>
#include <iostream>

int main()
{
    double simple = 100.0;
    double compound = 100.0;
    int year = 0;
    do {
        simple += 10.0;
        compound *= 1.05;
        ++year;
    } while (compound <= simple);
    std::cout << std::fixed << std::setprecision(2)
              << "year=" << year << " A=" << simple << " B=" << compound << '\n';
}
