// L05 示例 6：枚举值、作用域与底层类型（教材 4.6）
#include <iostream>

enum Color { red, green, blue };                    // 0、1、2
enum Week { Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun }; // 1..7
enum Level { none = 0, low = 1, high = 10, extra };  // extra=11

enum class Direction { north, south, east, west };
enum class Small : unsigned char { no, yes };

int main()
{
    std::cout << "red=" << red << " green=" << green << " blue=" << blue << '\n';
    std::cout << "Mon=" << Mon << " Wed=" << Wed << " Sun=" << Sun << '\n';
    std::cout << "none=" << none << " low=" << low
              << " high=" << high << " extra=" << extra << '\n';

    Week today = Wed;
    std::cout << "today 的数值 = " << today << '\n';
    if (today == Wed)
        std::cout << "today 是 Wed\n";
    std::cout << "today + 1 = " << today + 1 << "（表达式是整数运算）\n";

    Direction dir = Direction::north;
    std::cout << "Direction::north 的数值 = " << static_cast<int>(dir) << '\n';
    // std::cout << dir;  // 错误：enum class 不隐式转换成整数
    // Direction other = north; // 错误：必须写 Direction::north

    std::cout << "sizeof(Color) = " << sizeof(Color) << '\n';
    std::cout << "sizeof(Week) = " << sizeof(Week) << '\n';
    std::cout << "sizeof(Small) = " << sizeof(Small) << '\n';
    std::cout << "未固定底层类型的 enum 大小由实现选择，不能从枚举量个数直接推算。\n";
}
