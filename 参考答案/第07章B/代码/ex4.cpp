#include <iostream>
#include <limits>
#include <string>
struct Student { std::string name; std::string hobby; int level; };
int get_students(Student students[], int capacity);
void display_value(Student student);
void display_pointer(const Student* student);
void display_all(const Student students[], int count);
int main()
{
    Student students[3]{};
    int count = get_students(students, 3);
    if (count < 0) return 1;
    std::cout << "count=" << count << '\n';
    for (int i = 0; i < count; ++i) {
        display_value(students[i]);
        display_pointer(&students[i]);
    }
    display_all(students, count);
}
int get_students(Student students[], int capacity)
{
    int count = 0;
    while (count < capacity) {
        Student candidate{};
        if (!std::getline(std::cin, candidate.name)) {
            if (std::cin.eof()) return count;
            std::cerr << "Read error\n";
            return -1;
        }
        if (candidate.name.empty()) return count;
        if (!std::getline(std::cin, candidate.hobby) || !(std::cin >> candidate.level)
            || candidate.level < 0 || candidate.level > 10) {
            std::cerr << "Incomplete record or level outside 0..10\n";
            return -1;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        students[count++] = candidate;
    }
    return count;
}
void display_value(Student student)
{
    std::cout << "value: " << student.name << " | " << student.hobby << " | " << student.level << '\n';
}
void display_pointer(const Student* student)
{
    if (student == nullptr) return;
    std::cout << "pointer: " << student->name << " | " << student->hobby << " | " << student->level << '\n';
}
void display_all(const Student students[], int count)
{
    for (int i = 0; i < count; ++i) {
        std::cout << "array: " << students[i].name << " | " << students[i].hobby << " | " << students[i].level << '\n';
    }
}
