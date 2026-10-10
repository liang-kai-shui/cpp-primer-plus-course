#include <iostream>
struct Duration { int hours; int minutes; };
Duration add_duration(Duration first, Duration second);
void show_duration(Duration value);
int main()
{
    Duration first{1, 50}, second{2, 25};
    Duration total = add_duration(first, second);
    show_duration(total);
    show_duration(first);
}
Duration add_duration(Duration first, Duration second)
{
    int minutes = first.minutes + second.minutes;
    return {first.hours + second.hours + minutes / 60, minutes % 60};
}
void show_duration(Duration value)
{
    std::cout << value.hours << "h " << value.minutes << "m\n";
}
