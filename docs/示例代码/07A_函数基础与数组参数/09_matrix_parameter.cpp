#include <iostream>
long long sum_matrix(const int matrix[][3], int rows);
int main()
{
    int matrix[2][3]{{1, 2, 3}, {4, 5, 6}};
    std::cout << "total=" << sum_matrix(matrix, 2) << '\n';
    std::cout << "first row=" << sum_matrix(matrix, 1) << '\n';
    std::cout << "no rows=" << sum_matrix(matrix, 0) << '\n';
}
long long sum_matrix(const int matrix[][3], int rows)
{
    long long total = 0;
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < 3; ++column) total += matrix[row][column];
    }
    return total;
}
