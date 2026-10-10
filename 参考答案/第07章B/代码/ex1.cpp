#include <cmath>
#include <iostream>
#include <string>
struct Box { std::string maker; double height; double width; double length; double volume; };
void show_box(Box box);
bool update_volume(Box* box);
int main()
{
    Box box{};
    if (!std::getline(std::cin, box.maker) || box.maker.empty()
        || !(std::cin >> box.height >> box.width >> box.length)) {
        std::cerr << "Expected maker line and three dimensions\n";
        return 1;
    }
    if (!update_volume(&box)) {
        std::cerr << "Expected finite dimensions 0..1000\n";
        return 1;
    }
    show_box(box);
}
void show_box(Box box)
{
    std::cout << "maker=" << box.maker << " height=" << box.height << " width=" << box.width
              << " length=" << box.length << " volume=" << box.volume << '\n';
}
bool update_volume(Box* box)
{
    if (box == nullptr || !std::isfinite(box->height) || !std::isfinite(box->width) || !std::isfinite(box->length)
        || box->height < 0 || box->width < 0 || box->length < 0
        || box->height > 1000 || box->width > 1000 || box->length > 1000) return false;
    box->volume = box->height * box->width * box->length;
    return true;
}
