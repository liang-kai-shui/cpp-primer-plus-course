#include <iostream>

int main()
{
    int n = 4;
    int old = n++;
    int fresh = ++n;
    std::cout << "old=" << old << " fresh=" << fresh << " n=" << n << '\n';

    int values[]{10, 20, 30};
    int* p = values;
    int first = *p++;
    (*p)++;
    int third = *++p;
    std::cout << "first=" << first << " middle=" << values[1]
              << " third=" << third << '\n';

    int x = 0;
    int y = (x = 3, x + 2);
    std::cout << "x=" << x << " y=" << y << '\n';
}
