#include <iostream>
long long sum_matrix(const int matrix[][3], int rows);
long long sum_column(const int matrix[][3], int rows, int column);
int main()
{
    int matrix[2][3]{};
    for (int row = 0; row < 2; ++row) {
        for (int column = 0; column < 3; ++column) {
            if (!(std::cin >> matrix[row][column]) || matrix[row][column] < -1000 || matrix[row][column] > 1000) {
                std::cerr << "Expected six integers in [-1000,1000]\n";
                return 1;
            }
        }
    }
    std::cout << "total=" << sum_matrix(matrix, 2) << '\n';
    for (int column = 0; column < 3; ++column) {
        std::cout << "column " << column << '=' << sum_column(matrix, 2, column) << '\n';
    }
}
long long sum_matrix(const int matrix[][3], int rows)
{
    long long total = 0;
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < 3; ++column) total += matrix[row][column];
    }
    return total;
}
long long sum_column(const int matrix[][3], int rows, int column)
{
    long long total = 0;
    for (int row = 0; row < rows; ++row) total += matrix[row][column];
    return total;
}
