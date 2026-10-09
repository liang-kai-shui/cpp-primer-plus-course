#include <iostream>

int main()
{
    int sales[3][12]{};
    long long total = 0;
    for (int year = 0; year < 3; ++year) {
        long long year_total = 0;
        for (int month = 0; month < 12; ++month) {
            if (!(std::cin >> sales[year][month]) || sales[year][month] < 0) {
                std::cerr << "Invalid sales\n";
                return 1;
            }
            year_total += sales[year][month];
        }
        std::cout << "year " << year + 1 << '=' << year_total << '\n';
        total += year_total;
    }
    std::cout << "total=" << total << '\n';
}
