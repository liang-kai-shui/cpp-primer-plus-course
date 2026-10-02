// ===== 实验 D =====
// 整数除以 0。
// 你的预测：这会在哪一步出问题 —— 编译期？链接期？还是运行期？
//   如果运行期：程序会输出几行？退出码是多少？
// 编译命令: g++ -std=c++17 -Wall D_divide_by_zero.cpp -o D.exe
// 运行命令: .\D.exe ; echo "退出码: $LASTEXITCODE"
#include <iostream>
int main()
{
    int a = 10;
    int b = 0;
    std::cout << "程序开始运行" << std::endl;
    std::cout << "10 / 0 = " << a / b << std::endl;
    std::cout << "这一行会被打印吗？" << std::endl;
    return 0;
}