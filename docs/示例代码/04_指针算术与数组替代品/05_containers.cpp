#include <array>
#include <cstddef>
#include <iostream>
#include <vector>

int main()
{
    int raw[3]{1, 2, 3};
    std::array<int, 3> fixed{1, 2, 3};
    std::vector<int> growing{1, 2, 3};

    fixed.at(1) = 20;
    growing.push_back(4);

    std::cout << "raw[1] = " << raw[1] << '\n';
    std::cout << "fixed.at(1) = " << fixed.at(1) << '\n';
    std::cout << "growing.size() = " << growing.size() << '\n';
    for (std::size_t i = 0; i < growing.size(); ++i)
        std::cout << growing.at(i) << ' ';
    std::cout << '\n';
}
