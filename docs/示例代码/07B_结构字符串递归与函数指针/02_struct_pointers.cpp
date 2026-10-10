#include <iostream>
struct Box { double length; double width; double height; double volume; };
bool set_volume(Box* box);
void show_box(const Box* box);
int main()
{
    Box box{2, 3, 4, 0};
    set_volume(&box);
    show_box(&box);
    std::cout << "null accepted=" << set_volume(nullptr) << '\n';
}
bool set_volume(Box* box)
{
    if (box == nullptr) return false;
    box->volume = box->length * box->width * box->height;
    return true;
}
void show_box(const Box* box)
{
    if (box == nullptr) return;
    std::cout << "volume=" << box->volume << '\n';
}
