#include <iostream>

int main()
{
    int* p = new int{42};
    std::cout << "动态对象的值 = " << *p << '\n';
    *p = 50;
    std::cout << "修改后 = " << *p << '\n';

    delete p;
    p = nullptr;
    std::cout << "对象已释放，p 现在是 nullptr\n";

    // 不要再读 *p，也不要对同一对象重复 delete。
    // 如果另一个指针也存着旧地址，把 p 置空不会保护它。
}
