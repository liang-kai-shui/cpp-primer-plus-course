// ============================================================
//  实验 B：sizeof 和 strlen 的区别
// ------------------------------------------------------------
//  这个实验在验证什么：
//  sizeof 量的是"数组占多少字节"（编译期就算好，把结尾的 '\0' 也算进去），
//  strlen 数的是"到 '\0' 之前有几个字符"（运行时数，不含 '\0'）。
//  对同一个字符串来说，两者永远差 1。
//
//  实测结论：
//      char s1[] = "bubbles";    ->  sizeof 8,  strlen 7
//      char s2[20] = "bubbles";  ->  sizeof 20, strlen 7
//  第二行 sizeof 是 20，因为大小是自己写死的——
//  sizeof 量的是"柜子有多大"，和里面装了几个字无关；
//  strlen 数的才是"装了几个字"。
// ============================================================
#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    char s1[] = "bubbles";
    char s2[20] = "bubbles";
    std::cout << sizeof(s1) << " " << strlen(s1) << std::endl;
    std::cout << sizeof(s2) << " " << strlen(s2) << std::endl;
}