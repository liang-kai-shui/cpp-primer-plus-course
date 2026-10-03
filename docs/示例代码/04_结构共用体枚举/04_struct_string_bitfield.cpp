// L05 示例 4：string 成员与位字段（教材 4.4.3、4.4.6）
#include <iostream>
#include <string>

struct Person
{
    std::string name;
    std::string city;
    int age;
};

struct Date
{
    unsigned int day   : 5;    // 可表示 0..31；并不自动校验日期
    unsigned int month : 4;    // 可表示 0..15
    unsigned int year  : 12;   // 可表示 0..4095
};

int main()
{
    Person p{"Li Ming", "Zhengzhou", 19};
    Person q = p;              // std::string 成员也会被正确复制
    q.name = "Wang Fang";
    std::cout << "p.name = " << p.name << ", q.name = " << q.name << '\n';

    Date d{29, 2, 2024};
    std::cout << "日期: " << d.year << '-' << d.month << '-' << d.day << '\n';
    std::cout << "sizeof(Date) = " << sizeof(Date) << " 字节\n";
    std::cout << "sizeof(三个 unsigned int) = " << 3 * sizeof(unsigned int) << " 字节\n";
    std::cout << "位字段的排列和最终大小依赖实现；不能对 d.day 取地址。\n";

    // 可选实验：把 40 赋给 d.day，再观察编译器诊断和运行结果。
    // 不要依赖溢出后的值，也不要假设每个编译器都会给出同样的警告。
}
