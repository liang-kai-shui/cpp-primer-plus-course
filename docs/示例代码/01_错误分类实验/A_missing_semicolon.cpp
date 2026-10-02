// ===== 实验 A =====
// 这段代码有什么问题？编译一下，属于哪类错误？
// 编译命令: g++ -std=c++17 -Wall A_missing_semicolon.cpp -o A.exe
#include <iostream>
int main()
{
    std::cout << "hello世界" << std::endl
    return 0;
}