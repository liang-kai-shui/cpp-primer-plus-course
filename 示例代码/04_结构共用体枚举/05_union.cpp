// L05 示例 5：union 的成员共用存储空间（教材 4.5）
#include <iostream>

union Value
{
    int i;
    double d;
    char bytes[8];
};

// 标签由程序员维护：读值时必须检查它对应哪一个成员。
struct TaggedValue
{
    char tag;                     // 'i' 或 'd'
    union { int i; double d; };   // 匿名 union 的成员可直接用 .i / .d 访问
};

int main()
{
    std::cout << "sizeof(int) = " << sizeof(int) << '\n';
    std::cout << "sizeof(double) = " << sizeof(double) << '\n';
    std::cout << "sizeof(char[8]) = " << sizeof(char[8]) << '\n';
    std::cout << "sizeof(Value) = " << sizeof(Value) << '\n';
    std::cout << "union 的大小至少容纳最大成员；对齐也可能让它更大。\n";

    Value v{};                     // 首个成员 i 是活动成员
    v.i = 65;
    std::cout << "写入 i 后，读取 i: " << v.i << '\n';
    v.d = 3.14159;                 // 现在 d 是活动成员
    std::cout << "写入 d 后，读取 d: " << v.d << '\n';
    // 不要在这里读 v.i：它已不是活动成员，结果不受标准保证。

    std::cout << "&v.i = " << static_cast<const void*>(&v.i) << '\n';
    std::cout << "&v.d = " << static_cast<const void*>(&v.d) << '\n';
    std::cout << "两个成员从同一地址开始；取地址不会读取非活动成员的值。\n";

    TaggedValue a{};
    a.i = 42;
    a.tag = 'i';
    TaggedValue b{};
    b.d = 2.718;
    b.tag = 'd';

    if (a.tag == 'i')
        std::cout << "a: " << a.i << '\n';
    if (b.tag == 'd')
        std::cout << "b: " << b.d << '\n';
}
