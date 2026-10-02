// ============================================================
//  示例 6：auto 的陷阱              ★ 教材 p85 专门警告过
//              （对应教材 3.4.5 p83-84、复习题第 10 题）
// ============================================================
#include <iostream>
#include <typeinfo>             // typeid().name() 能看出变量的真实类型

int main()
{
    using namespace std;

    cout << "===== 教材 p85 的那个陷阱 =====\n";
    auto   x = 0.0;             // 0.0 是 double
    double y = 0;               // 0 是 int，但显式声明了 double，会转换
    auto   z = 0;               // 0 是 int -> z 就是 int！
    cout << "auto x = 0.0;   x 的类型是 " << typeid(x).name() << "  (d = double)\n";
    cout << "double y = 0;   y 的类型是 " << typeid(y).name() << "  (d = double)\n";
    cout << "auto z = 0;     z 的类型是 " << typeid(z).name() << "  (i = int) ← 踩坑了！\n";
    cout << "\n【结论】const 不写类型没关系，auto 不写类型就危险：\n";
    cout << "  double y = 0;   -> y 是 0.0（安全）\n";
    cout << "  auto   z = 0;   -> z 是 0（int，后面 1/2 就变 0 了）\n";
    cout << "  用 auto 时，字面值的写法决定了类型。\n";

    cout << "\n===== 复习题第 10 题：这些变量都是什么类型？=====\n";
    auto a = 15;                // ?
    auto b = 150.37f;           // ?
    auto c = 'B';               // ?
    auto d = 8.25f / 2.5;       // ?
    cout << "auto a = 15;           -> " << typeid(a).name() << "  (i = int)\n";
    cout << "auto b = 150.37f;      -> " << typeid(b).name() << "  (f = float，因为后缀 f)\n";
    cout << "auto c = 'B';          -> " << typeid(c).name() << "  (c = char)\n";
    cout << "auto d = 8.25f / 2.5;  -> " << typeid(d).name() << "  (d = double，float 被提升为 double)\n";

    cout << "\n===== 整数后缀决定类型（教材 3.1.6 p62-64）=====\n";
    cout << "复习题第 4 题：33L 和 33 有什么区别？\n";
    auto n1 = 33;               // int
    auto n2 = 33L;              // long
    cout << "  auto n1 = 33;   -> " << typeid(n1).name() << " (i = int)\n";
    cout << "  auto n2 = 33L;  -> " << typeid(n2).name() << " (l = long)\n";
    cout << "  值一样，类型不同。当数值超过 int 范围时，写不写 L 就决定成败。\n";

    cout << "\n【auto 什么时候真有用】类型名长得离谱的时候：\n";
    cout << "  std::vector<double>::iterator p = v.begin();  // 老写法，啰嗦\n";
    cout << "  auto p = v.begin();                            // C++11，清爽\n";
    cout << "  （等 L21 学 STL 时你会体会到）\n";

    return 0;
}