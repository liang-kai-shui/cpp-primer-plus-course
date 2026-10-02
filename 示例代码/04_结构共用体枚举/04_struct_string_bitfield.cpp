// ============================================================
//  L05 · 示例 4：结构里放 string；以及「位字段」
//              （教材 4.4.3 p108 / 4.4.6 p111）
// ------------------------------------------------------------
//  ⚠️ 本文件编译时会【故意】产生一条警告：
//     warning: conversion from 'unsigned int' to 'unsigned char:5'
//              changes value from '40' to '8' [-Woverflow]
//  这是演示「位字段装不下会怎样」用的，请把这条警告当成教材的一部分。
// ============================================================
#include <iostream>
#include <string>

// ---------- 结构成员可以是 string ----------
// 教材 p108 专门回答过「结构可以将 string 类作为成员吗」——可以。
// 关键原因：string 自己知道怎么复制、怎么释放内存，不需要你操心。
struct Person
{
    std::string name;
    std::string city;
    int         age;
};

// ---------- 位字段：用「几个比特」来存一个成员，省内存 ----------
// 语法：  类型  成员名 : 位数;
struct Date
{
    unsigned int day   : 5;    // 5 位 -> 0..31，够表示日期
    unsigned int month : 4;    // 4 位 -> 0..15，够表示月份
    unsigned int year  : 12;   // 12 位 -> 0..4095，够表示年份
};
// 5+4+12 = 21 位，一个 4 字节的 unsigned int 就装得下。

int main()
{
    using namespace std;

    // ---------- string 成员 ----------
    Person p = {"Li Ming", "Zhengzhou", 19};
    cout << "string 成员: " << p.name << " / " << p.city << " / " << p.age << "\n";
    cout << "  C++11 起可以直接 {..} 初始化，不用操心底层内存\n";

    Person q = p;                      // 整体复制也没问题
    q.name = "Wang Fang";
    cout << "  Person q = p; 再改 q.name 之后：p.name = " << p.name
         << ", q.name = " << q.name << "   <- 各有一份\n";

    // ---------- 位字段 ----------
    cout << "\n===== 位字段 =====\n";
    Date d = {29, 2, 2024};
    cout << "日期: " << d.year << "-" << d.month << "-" << d.day << "\n";
    cout << "sizeof(Date) = " << sizeof(Date) << " 字节\n";
    cout << "  若用三个普通 int 存，要 " << sizeof(int) * 3 << " 字节\n";

    // 位字段装不下时，编译器【会】警告（-Woverflow），值被截断
    // 这一点和 L04 的数组越界【不一样】：数组越界连警告都没有。
    Date d2 = {0, 0, 0};
    d2.day = 40;                       // 5 位最大只能到 31
    cout << "\n把 day 设为 40（5 位最大 31）: day = " << d2.day << "\n";
    cout << "  编译时你会看到这样一条警告：\n";
    cout << "    warning: conversion from 'unsigned int' to 'unsigned char:5'\n";
    cout << "             changes value from '40' to '8' [-Woverflow]\n";
    cout << "  值被截断成 8（40 减去 32），而且【编译器提前提醒了你】。\n";
    cout << "  对比 L04 的数组越界：那个是连警告都没有的。\n";
    cout << "  所以：警告不是噪音，是编译器在帮你 —— 但前提是你开了 -Wall。\n";

    cout << "\n【结论】\n";
    cout << "  位字段能省内存，但它：\n";
    cout << "    1. 不能取地址（&d.day 是错的）\n";
    cout << "    2. 具体布局依赖编译器，可移植性差\n";
    cout << "    3. 装不下时值被截断（编译器会警告 -Woverflow，但不开 -Wall 就看不到）\n";
    cout << "  日常几乎用不到。你只需要【认识这种写法】，能读懂别人的代码就够了。\n";

    return 0;
}
