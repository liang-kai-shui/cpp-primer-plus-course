#include <array>
#include <cstddef>
#include <iostream>

int main()
{
    std::array<int, 4> scores{80, 90, 70, 100};
    int sum = 0;
    int best = scores.at(0);
    for (std::size_t i = 0; i < scores.size(); ++i)
    {
        int score = scores.at(i);
        sum += score;
        if (score > best)
            best = score;
    }
    std::cout << "平均分: " << static_cast<double>(sum) / scores.size() << '\n';
    std::cout << "最高分: " << best << '\n';
}
