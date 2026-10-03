#include <iostream>

int main()
{
    int count = 0;
    std::cout << "要记录几个分数（1～100）？";
    if (!(std::cin >> count) || count < 1 || count > 100)
    {
        std::cerr << "请输入 1～100 之间的整数。\n";
        return 1;
    }

    int* scores = new int[count]{};
    int sum = 0;
    for (int i = 0; i < count; ++i)
    {
        scores[i] = 60 + i;
        sum += scores[i];
    }
    std::cout << "平均分 = " << static_cast<double>(sum) / count << '\n';

    delete[] scores;
    scores = nullptr;
}
