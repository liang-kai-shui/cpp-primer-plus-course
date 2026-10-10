#include <iostream>
#include <string>
std::string make_greeting(std::string name);
void show_names(const std::string names[], int count);
int main()
{
    std::string name = "Li Ming";
    std::cout << make_greeting(name) << '\n';
    std::cout << "original=" << name << '\n';
    std::string names[]{"Li Ming", "Han Mei", "Kai Shui"};
    show_names(names, 3);
}
std::string make_greeting(std::string name)
{
    name = "Hello, " + name;
    return name;
}
void show_names(const std::string names[], int count)
{
    for (int i = 0; i < count; ++i) std::cout << i + 1 << ": " << names[i] << '\n';
}
