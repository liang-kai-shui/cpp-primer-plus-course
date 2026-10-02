// ============================================================
//  L04 · 示例 6：混合输入数字和字符串的陷阱  ★★ 人人都会踩 ★★
//              （教材 4.2.5, p98-99）
// ------------------------------------------------------------
//  这个坑 99% 的 C++ 初学者都会踩，而且现象非常诡异：
//  程序好像「跳过了」你的输入。这一节必须亲自跑通。
// ============================================================
#include <iostream>
#include <cstdlib>              // atoi 在这里

int main()
{
    using namespace std;

    // ================= 错误示范 =================
    cout << "===== 错误示范 =====" << endl;
    int year;
    char address[80];

    cout << "Enter the year: ";
    cin >> year;                        // <- 问题就在这一行
    cout << "Enter the address: ";
    cin.getline(address, 80);           // <- 它读到了「空行」！

    cout << "  year    = " << year << endl;
    cout << "  address = \"" << address << "\"   <- 空的！\n";
    cout << "\n  【原因】cin >> year 只取走了数字，\n";
    cout << "         你按的回车（换行符）【还留在输入队列里】。\n";
    cout << "         接着 getline 一看：第一个字符就是换行，\n";
    cout << "         说明这一行是空的，于是它读了个寂寞。\n";

    // ================= 三种正确解法 =================
    cout << "\n===== 三种解法（下面请重新输入）=====" << endl;

    int y1, y2, y3;
    char addr1[80], addr2[80], addr3[80];

    // ---- 解法 1：读完数字后，手动吃掉换行符 ----
    cout << "\n[解法1] Enter the year: ";
    cin >> y1;
    cin.get();                          // <- 就这一行，把换行符吃掉
    cout << "[解法1] Enter the address: ";
    cin.getline(addr1, 80);
    cout << "  -> " << y1 << " / \"" << addr1 << "\"  正确\n";

    // ---- 解法 2：把两步连起来写 ----
    cout << "\n[解法2] Enter the year: ";
    (cin >> y2).get();                  // <- cin >> y2 返回 cin，再对它调 get()
    cout << "[解法2] Enter the address: ";
    cin.getline(addr2, 80);
    cout << "  -> " << y2 << " / \"" << addr2 << "\"  正确\n";

    // ---- 解法 3：干脆全部用 getline，数字再自己转 ----
    cout << "\n[解法3] Enter the year: ";
    char buf[80];
    cin.getline(buf, 80);
    y3 = atoi(buf);                     // 字符串 -> 整数
    cout << "[解法3] Enter the address: ";
    cin.getline(addr3, 80);
    cout << "  -> " << y3 << " / \"" << addr3 << "\"  正确\n";

    cout << "\n【推荐】解法 1 最直观；写多了你会自然用解法 2。\n";
    cout << "        学会 std::string 后更常用解法 3（用 stoi）。\n";

    return 0;
}