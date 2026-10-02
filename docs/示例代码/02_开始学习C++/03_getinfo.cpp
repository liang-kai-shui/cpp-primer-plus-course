// ============================================================
//  示例 3：cin 输入（对应教材 p41-42、程序清单 2.3/2.4）
// ------------------------------------------------------------
//  演示 cin >> 的两副面孔：
//    - 读数字：好用到没话说
//    - 读字符串：只读到"第一个空白符"就停！这是个坑
// ============================================================

#include <iostream>
int main()
{
    using namespace std;

    // ---------- 第一部分：读数字 ----------
    int carrots;
    cout << "How many carrots do you have? ";
    cin >> carrots;                                  // 从键盘读一个整数
    cout << "Here are two more. ";
    carrots = carrots + 2;
    cout << "Now you have " << carrots << " carrots." << endl;

    // ---------- 第二部分：读字符串 ----------
    // char name[20] 是一个"字符数组"，能装 19 个字符 + 1 个结束符
    // （数组是第 4 章的内容，这里先照着用，知道它"能装字符串"就行）
    char name[20];
    cout << "Enter your name: ";
    cin >> name;                                     // ⚠️ 只读到空白符为止！
    cout << "Hello, " << name << "!" << endl;

    cout << endl;
    cout << "【实验】如果刚才输入的是 \"Li Ming\"，这里只会显示 \"Li\"。" << endl;
    cout << "        因为 cin >> 遇到空格就停了。想读整行要用 cin.getline()（第 4 章）。" << endl;

    return 0;
}