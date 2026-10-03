#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int age;
};

int next_id()
{
    static int id = 0;      // 第一次调用时初始化，之后一直保留值
    return ++id;
}

int main()
{
    Student* p = new Student{"Li Ming", 19};
    std::cout << "p->name = " << p->name << '\n';
    std::cout << "(*p).age = " << (*p).age << '\n';
    delete p;
    p = nullptr;

    int automatic = 10;     // 局部自动对象
    std::cout << "automatic = " << automatic << '\n';
    std::cout << "static ids: " << next_id() << ", " << next_id() << '\n';
}
