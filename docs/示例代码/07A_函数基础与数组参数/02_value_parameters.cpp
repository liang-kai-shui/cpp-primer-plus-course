#include <iostream>
int next_value(int number);
void change_copy(int number);
int main()
{
    int number = 8;
    change_copy(number);
    std::cout << "original=" << number << '\n';
    next_value(number); // 故意丢弃返回值，用来对比下一行。
    std::cout << "after discarded result=" << number << '\n';
    number = next_value(number);
    std::cout << "after assignment=" << number << '\n';
}
void change_copy(int number)
{
    number = 99;
    std::cout << "copy=" << number << '\n';
}
int next_value(int number)
{
    return number + 1;
}
