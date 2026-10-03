#include <iostream>

int main()
{
    int count = 0;
    if (!(std::cin >> count) || count < 1 || count > 100)
    {
        std::cerr << "人数必须是 1～100 的整数。\n";
        return 1;
    }

    int* scores = new int[count]{};
    long long sum = 0;
    for (int i = 0; i < count; ++i)
    {
        if (!(std::cin >> scores[i]))
        {
            std::cerr << "分数输入失败。\n";
            delete[] scores;
            return 1;
        }
        sum += scores[i];
    }

    std::cout << "平均分: " << static_cast<double>(sum) / count << '\n';
    delete[] scores;
}
