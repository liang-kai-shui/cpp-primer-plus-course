// ============================================================
//  示例 2：螺旋矩阵（函数化重构）
// ------------------------------------------------------------
//  这个示例以 一份练习用的螺旋矩阵代码 为原型。
//  （说明：这份代码保留了原样，此处只作为
//    "如何把一堆塞在 main 里的逻辑拆成函数"的对照素材。）
//
//  【先说好的地方】原程序的算法完全正确。螺旋矩阵的边界控制
//  （top / bottom / left / right 四条边 + 两个 if 保护）是这道题
//  最容易写错的地方，它写对了。
//
//  【再说要改的】原程序有两个"工程习惯"问题：
//    1. 第 7 行有个 int hellao; 声明了但从没用过
//       → 打开 -Wall 后编译器会警告：
//         cube.cpp:7:9: warning: unused variable 'hellao' [-Wunused-variable]
//       → 用不到的变量要删掉。留着会让读代码的人以为它有用途。
//
//    2. 全部 60 行逻辑塞在 main 里，没有函数级的划分
//       → 拆成 make_spiral() 和 print_matrix() 后：
//          · main 变成 5 行，一眼看懂程序在干什么
//          · 生成和打印可以分别测试、分别复用
//          · 出错时你知道该去哪个函数找
//
//  这就是教材第 7 章要讲的核心思想：**把程序拆成函数**。
//  第 7 章标题就叫「函数——C++ 的编程模块」，它是从"会做题"
//  走向"会写程序"的分水岭。
//
//  对照阅读：教材 7.1 复习函数的基本知识 (p219)
//            教材 7.2 函数参数和按值传递 (p224)，看 p227 的示例
// ============================================================

#include <iostream>
#include <vector>

// 类型别名：给又长又啰嗦的类型起个短名字，读起来清爽很多。
// 教材 7.10.4 (p265) 讲类似的 typedef；这里的 using 是 C++11 的写法。
using Matrix = std::vector<std::vector<long long>>;

// ------------------------------------------------------------
//  函数原型
// ------------------------------------------------------------
Matrix make_spiral(int n);
void   print_matrix(const Matrix& m);

// ------------------------------------------------------------
//  make_spiral：生成 n×n 的螺旋矩阵（顺时针，从 1 开始）
//
//  参数 n 按值传递 —— 因为函数需要一个可修改的副本吗？
//  不，是因为 int 只有 4 字节，复制代价可以忽略。
//  【经验法则】内置小类型（int/double/char）按值传；
//              大对象（string/vector/自定义类）用 const 引用传。
// ------------------------------------------------------------
Matrix make_spiral(int n)
{
    // n 是 int，n*n 可能溢出 int（n 大到 46341 时）。
    // 所以用 long long 参与乘法：1LL 把整个表达式提升为 long long。
    // 这类"隐式溢出"是教材第 3 章 (p79 类型转换) 的重点。
    const long long total = 1LL * n * n;

    Matrix matrix(n, std::vector<long long>(n, 0));

    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    long long num = 1;

    while (num <= total)
    {
        for (int i = left; i <= right; ++i)  matrix[top][i] = num++;      // 上边：左→右
        ++top;

        for (int i = top; i <= bottom; ++i)  matrix[i][right] = num++;    // 右边：上→下
        --right;

        if (top <= bottom)                                                // 下边：右→左
        {
            for (int i = right; i >= left; --i) matrix[bottom][i] = num++;
            --bottom;
        }

        if (left <= right)                                                // 左边：下→上
        {
            for (int i = bottom; i >= top; --i) matrix[i][left] = num++;
            ++left;
        }
    }
    return matrix;
}

// ------------------------------------------------------------
//  print_matrix：只负责打印
//
//  参数是 const Matrix& —— 只读，且不复制整个矩阵。
//  注意列对齐：如果数字位数不同，空格数量要能对齐才好看。
// ------------------------------------------------------------
void print_matrix(const Matrix& m)
{
    for (std::size_t i = 0; i < m.size(); ++i)
    {
        for (std::size_t j = 0; j < m[i].size(); ++j)
        {
            if (j != 0) std::cout << ' ';
            std::cout << m[i][j];
        }
        std::cout << '\n';
    }
}

// ------------------------------------------------------------
//  main：现在它只表达"程序的意图"，不包含算法细节
// ------------------------------------------------------------
int main()
{
    std::cout << "请输入 n (生成 n x n 螺旋矩阵): ";

    int n = 0;
    if (!(std::cin >> n) || n <= 0)     // 顺手做输入检查，别信任用户
    {
        std::cout << "输入无效，需要正整数。\n";
        return 1;
    }

    const Matrix m = make_spiral(n);
    print_matrix(m);

    return 0;
}
