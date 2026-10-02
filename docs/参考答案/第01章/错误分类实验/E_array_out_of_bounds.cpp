// ===== 实验 E =====
// 数组 a 只有 3 个元素（a[0], a[1], a[2]），但循环访问到了 a[3]。
// 你的预测：编译会通过吗？程序会崩溃吗？输出会是什么？
// 编译命令: g++ -std=c++17 -Wall -Wextra E_array_out_of_bounds.cpp -o E.exe
// 运行命令: .\E.exe
#include <iostream>
int main()
{
    int a[3] = {1, 2, 3};
    for (int i = 0; i <= 3; ++i)   // 注意是 <= 3
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}