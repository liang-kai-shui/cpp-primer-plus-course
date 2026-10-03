#include <iostream>

int main()
{
    int values[4]{10, 20, 30, 40};
    int* first = values;
    int* end = values + 4;       // 合法的尾后位置，不可解引用

    for (int* p = first; p != end; ++p)
        std::cout << *p << ' ';
    std::cout << '\n';
    std::cout << "p[2] = " << first[2]
              << ", *(p+2) = " << *(first + 2) << '\n';
    std::cout << "元素数 = " << end - first << '\n';

    int* p = values;
    (*p)++;                    // 改第一个元素：10 -> 11
    p++;                       // 改指针：现在指向第二个元素
    std::cout << "values[0] = " << values[0] << ", *p = " << *p << '\n';
}
