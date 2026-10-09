#include <array>
#include <iostream>

int main()
{
    std::array<long long, 11> facts{};
    facts[0] = 1;
    for (int i = 1; i <= 10; ++i) {
        facts[i] = facts[i - 1] * i;
    }
    for (int i = 0; i <= 10; ++i) {
        std::cout << i << "!=" << facts[i] << '\n';
    }
    // 本例止于 10!；不要直接扩到 100! 后仍用 long long。
}
