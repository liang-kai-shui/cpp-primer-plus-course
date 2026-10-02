// ============================================================
//  编程练习 3：用 char 数组把"姓, 名"拼成一个字符串（教材 p124）
//  题目要求用 char 数组 + <cstring> 里的函数，
//  把结果"存储"到一个变量里再显示（不是直接打印）。
// ------------------------------------------------------------
//  这题在练什么：C 风格字符串的拼接三步曲——
//      1. strcpy(dest, src)  复制
//      2. strcat(dest, src)  追加
//      3. strcat(dest, src)  再追加
//  顺序是：先复制"姓"，再追加 ", "，最后追加"名"。
//  目标数组必须留足空间（本例用了 40 字节，13 个字符 + '\0' 绰绰有余）。
//
//  预期行为（输入 Flip / Fleming）：
//      Enter your first name: Enter your last name: 
//      Here's the information in a single string: Fleming, Flip
//
//  ⚠️ 关于"换行符残留"：连着两次 cin.getline() 不会出问题，
//  因为 getline 会把自己那一行的换行符丢掉。
// ============================================================
#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    char f_name[20];
    char l_name[20];
    char full_name[40];
    cout << "Enter your first name: ";
    cin.getline(f_name, 20);
    cout << "Enter your last name: ";
    cin.getline(l_name, 20);
    strcpy(full_name, l_name);
    strcat(full_name, ", ");
    strcat(full_name, f_name);
    cout << "Here's the information in a single string: " << full_name;
    return 0;
}