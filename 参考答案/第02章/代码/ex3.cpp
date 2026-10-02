// ============================================================
// 教材：《C++ Primer Plus（第 6 版）》第 2 章 开始学习 C++
// 题目：编程练习 3（教材 p53–54）——用 3 个用户定义的函数生成 4 行输出
// ------------------------------------------------------------
// 思路要点：
//   1. output1() 输出一行 "Three blind mice"，output2() 输出一行 "See how they run"；
//   2. main() 里各调用两次（一共 4 行调用语句），main() 自己完全不出现 cout；
//   3. 两个函数都在 main() 之前写了函数原型。
// 值得注意：
//   两个函数定义的末尾都多写了一个分号（};）。C++ 允许这种多余的
//   分号（它是一条空声明），编译不会报错，但风格上应当去掉。
// ============================================================

#include <iostream>

void output1(void);
void output2(void);

void output1(void)
{
    std::cout << "Three blind mice\n";
};

void output2(void)
{
    std::cout << "See how they run\n";
};

int main()
{
    using namespace std;

    output1();
    output1();
    output2();
    output2();
    return 0;
}