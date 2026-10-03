#include <cstddef>
#include <iostream>
#include <vector>

int main()
{
    int count = 0;
    if (!(std::cin >> count) || count < 1 || count > 100)
    {
        std::cerr << "人数必须是 1～100 的整数。\n";
        return 1;
    }

    std::vector<int> scores(static_cast<std::size_t>(count));
    for (std::size_t i = 0; i < scores.size(); ++i)
    {
        if (!(std::cin >> scores.at(i)))
        {
            std::cerr << "分数输入失败。\n";
            return 1;
        }
    }

    int best = scores.at(0);
    for (std::size_t i = 1; i < scores.size(); ++i)
        if (scores.at(i) > best)
            best = scores.at(i);
    std::cout << "最高分: " << best << '\n';
}
