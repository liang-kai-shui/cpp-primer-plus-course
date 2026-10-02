// ============================================================
//  编程练习 4：用 string 对象做同样的事（教材 p124）
//  和练习 3 是同一道题，区别是这里用 std::string。
// ------------------------------------------------------------
//  这题在练什么：对照练习 3 体会 string 省掉了什么——
//  不用管数组大小、不用记 strcpy/strcat 的顺序，
//  拼接就是一个 + 号：full_name = l_name + ", " + f_name;
//  读取整行用 getline(cin, 变量)（注意：是 getline(cin, s)，没有那个点）。
//
//  预期行为（输入 Flip / Fleming）：
//      Enter your first name: Enter your last name: 
//      Here's the information in a single string: Fleming, Flip
//
//  ⚠️ 严格说这里该包含 <string>：
//  文件里目前写的是 #include <cstring>。
//  <cstring> 提供的是 strcpy / strcat / strlen / strcmp 这些 C 风格字符串函数，
//  getline(cin, string) 和 std::string 应该在 <string> 里。
//  本机之所以能编过，是因为 <iostream> 间接地把 <string> 也带了进来
//  （实现细节，不是标准保证）。为保持与验证过的版本一致，此处代码原样保留。
// ============================================================
#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    string f_name, l_name, full_name;
    cout << "Enter your first name: ";
    getline(cin, f_name);
    cout << "Enter your last name: ";
    getline(cin, l_name);
    full_name = l_name + ", " + f_name;
    cout << "Here's the information in a single string: " << full_name;
    return 0;
}