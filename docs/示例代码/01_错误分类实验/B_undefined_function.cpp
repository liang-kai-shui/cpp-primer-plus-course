// ===== 实验 B =====
// add 函数只有"声明"（说明书），没有"定义"（函数体）。
// 编译一下：属于哪类错误？报错里的关键词是什么？
// 编译命令: g++ -std=c++17 -Wall B_undefined_function.cpp -o B.exe
#include <iostream>

int add(int a, int b);      // 声明

int main()
{
    std::cout << add(1, 2) << std::endl;
    return 0;
}