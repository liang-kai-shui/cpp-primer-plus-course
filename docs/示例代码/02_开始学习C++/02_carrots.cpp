// ============================================================
//  示例 2：声明、赋值、输出变量（对应教材 p38-40）
// ============================================================

#include <iostream>
int main()
{
    using namespace std;

    int carrots; // 【声明语句】告诉编译器：有个叫 carrots 的变量，类型是 int
                 // ⚠️ 此刻它里面的值是"垃圾"（内存里原来的东西），不是 0

    carrots = 25; // 【赋值语句】把 25 放进 carrots

    cout << "I have ";
    cout << carrots; // cout 会自动把 int 转成文字输出 —— 这就是"智能对象"
    cout << " carrots.";
    cout << endl;

    carrots = carrots - 1; // 右边先算，再存回左边
    cout << "Crunch, crunch. Now I have " << carrots << " carrots." << endl;

    // ---- 一个实验：不初始化就用，会怎样？----
    // ⚠️ 下面两行会触发一个警告：
    //     warning: 'garbage' is used uninitialized in this function [-Wuninitialized]
    //    ★ 这个警告是**故意留着**的，它是本示例的重点 ★
    //    它证明了第 1 章讲过的那件事：开 -Wall 后，编译器会主动帮你找 bug。
    //    如果编译时不加 -Wall，这个 bug 会静悄悄地溜过去。
    int garbage;             // 只声明，不赋值 —— 里面是内存里的垃圾值
    cout << "未初始化的变量是: " << garbage << "  <- 每次运行可能都不一样" << endl;

    return 0;
}