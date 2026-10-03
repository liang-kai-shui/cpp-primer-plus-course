#include <iostream>

int main()
{
    int* p = nullptr;
    if (p == nullptr)
        std::cout << "p 暂时不指向对象，不能使用 *p\n";

    int value = 7;
    p = &value;
    if (p != nullptr)
        std::cout << "现在 *p = " << *p << '\n';

    // 下列语句只供阅读，不要取消注释运行：
    // int* uninitialized; *uninitialized = 1; // 地址未初始化
    // p = nullptr; std::cout << *p;             // 空指针解引用
}
