#include <cmath>
#include <iomanip>
#include <iostream>
struct Rect { double x; double y; };
struct Polar { double distance; double radians; };
Polar to_polar(Rect point);
int main()
{
    Rect point{};
    if (!(std::cin >> point.x >> point.y) || !std::isfinite(point.x) || !std::isfinite(point.y)
        || std::abs(point.x) > 1e6 || std::abs(point.y) > 1e6) {
        std::cerr << "Expected finite coordinates in [-1000000,1000000]\n";
        return 1;
    }
    Polar answer = to_polar(point);
    std::cout << std::fixed << std::setprecision(3) << "distance=" << answer.distance;
    if (answer.distance == 0) std::cout << " direction=undefined at origin\n";
    else std::cout << " degrees=" << answer.radians * 180.0 / std::acos(-1.0) << '\n';
}
Polar to_polar(Rect point)
{
    Polar answer{};
    answer.distance = std::sqrt(point.x * point.x + point.y * point.y);
    if (answer.distance != 0) answer.radians = std::atan2(point.y, point.x);
    return answer;
}
