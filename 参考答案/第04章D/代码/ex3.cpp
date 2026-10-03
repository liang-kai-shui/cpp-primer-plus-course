#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int age;
};

int main()
{
    Student* student = new Student{"Li Ming", 19};
    std::cout << student->name << ", " << student->age << '\n';
    delete student;
    student = nullptr;
}
