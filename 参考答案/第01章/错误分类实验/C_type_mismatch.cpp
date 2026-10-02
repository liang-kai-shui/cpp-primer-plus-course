// ===== 标本：类型不匹配（这是【编译错误】）=====
// 用整数去初始化一个 string 对象。类型不兼容。
// 编译一下，注意报错里的关键词 conversion ... requested。
// 编译命令: g++ -std=c++17 C_type_mismatch.cpp -o C_type_mismatch.exe
#include <string>

int main()
{
    std::string s = 12345;      // 不能用整数初始化 string
    return 0;
}