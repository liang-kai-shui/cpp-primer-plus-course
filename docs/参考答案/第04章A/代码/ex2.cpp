// ============================================================
//  编程练习 2：把程序清单 4.4 改用 string 类（教材 p124）
//  清单 4.4（教材 p95-96，instr1.cpp）原本用 cin >> 读两个 char 数组，
//  本练习要求改用 C++ 的 string 类。
// ------------------------------------------------------------
//  这题在练什么：把 char 数组换成 std::string 之后，
//  不用再写数组大小、也不用担心装不下；
//  cin >> string 同样是"遇空白就停"（只读一个单词，本题本来就读单词，够用）。
//
//  预期行为（输入 Li Ming / Ice Cream）：
//      Enter your name:
//      Enter your favorite dessert:
//      I have some delicious Ming for you, Li.
//  （注意：cin >> 遇空格就停，所以 "Li Ming" 只读进了 "Li"，
//    "Ming" 被下一个 cin >> 当成了甜点名——这是 cin >> 的固有限制，
//    本题就是用它来体会这一点。）
//
//  ⚠️ 严格说这里该包含 <string>：
//  文件里目前写的是 #include <cstring>。
//  <cstring> 提供的是 strcpy / strcat / strlen / strcmp 这些 C 风格字符串函数，
//  std::string 应该在 <string> 里。本机之所以能编过，
//  是因为 <iostream> 间接地把 <string> 也带了进来（实现细节，不是标准保证）。
//  为保持与验证过的版本一致，此处代码原样保留、不做改动。
// ============================================================
#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    // const int ArSize = 20;
    // char name[ArSize];
    // char dessert[ArSize];
    string name, dessert;

    cout << "Enter your name:\n";
    cin >> name;
    cout << "Enter your favorite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}