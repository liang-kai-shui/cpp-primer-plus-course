// ===== 实验 C =====
// 第 1 行的 #include 后面多写了一个分号。
// 你的预测：编译会 (1) 报错 还是 (2) 通过？
//   如果通过，是完全没提示，还是有个 warning？
// 编译命令: g++ -std=c++17 -Wall C_extra_semicolon.cpp -o C.exe
#include <iostream>;
int main()
{
    std::cout << "能跑吗" << std::endl;
    return 0;
}