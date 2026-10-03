#include <iostream>

int main()
{
    int score = 90;
    int* p = &score;
    std::cout << "score = " << score << ", *p = " << *p << '\n';
    std::cout << "&score = " << &score << ", p = " << p << '\n';
    std::cout << "&p = " << &p << "（指针变量自己的地址）\n";

    *p = 95;
    std::cout << "修改 *p 后，score = " << score << '\n';
}
