// ============================================================
//  编程练习 1：请求并显示姓名 / 成绩 / 年龄（教材 p124）
//  对应教材示例输出：
//      What is your first name? Betty Sue
//      What is your last name? Yewe
//      What letter grade do you deserve? B
//      What is your age? 22
//      Name: Yewe, Betty Sue
//      Grade: C
//      Age: 22
// ------------------------------------------------------------
//  这题在练什么：
//  1. 名字要含空格 -> 只能用 cin.getline() 读整行，不能用 cin >>；
//  2. 成绩是单个字符、年龄是数字 -> 用 cin.get() / cin >>；
//  3. 所以必然撞上"混合输入"陷阱：cin >> 之后残留的换行符，
//     要在下一次读整行之前用 cin.get() 清掉。
//  "成绩上调一个字母"用字符运算实现：letter_grade[0] + 1
//  （因为 char 本质就是个小整数，'B' + 1 == 'C'）。
//
//  预期行为（输入 Betty Sue / Yewe / B / 22）：
//      Name: Yewe, Betty Sue
//      Grade: C
//      Age: 22
// ============================================================
#include <iostream>

int main()
{
    using namespace std;
    char f_name[20], l_name[20];
    char letter_grade[5];
    int age;
    cout << "What is your first name? ";
    cin.getline(f_name, 20);
    cout << "What is your last name? ";
    cin.getline(l_name, 20);
    cout << "What letter grade do you deserve? ";
    cin.get(letter_grade, 5);
    cin.get();
    cout << "What is your age? ";
    cin >> age;
    cout << "Name: " << l_name << ", " << f_name;
    letter_grade[0] = letter_grade[0] + 1;
    cout << "\nGrade: " << letter_grade;
    cout << "\nAge: " << age;
    return 0;
}