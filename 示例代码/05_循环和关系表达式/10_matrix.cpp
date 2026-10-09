#include <iostream>

int main()
{
    const int rows = 2;
    const int cols = 3;
    int sales[rows][cols]{{10, 20, 30}, {40, 50, 60}};
    int total = 0;
    for (int row = 0; row < rows; ++row) {
        int row_total = 0;
        for (int col = 0; col < cols; ++col) row_total += sales[row][col];
        std::cout << "row " << row << '=' << row_total << '\n';
        total += row_total;
    }
    for (int col = 0; col < cols; ++col) {
        int col_total = 0;
        for (int row = 0; row < rows; ++row) col_total += sales[row][col];
        std::cout << "col " << col << '=' << col_total << '\n';
    }
    std::cout << "total=" << total << '\n';
}
