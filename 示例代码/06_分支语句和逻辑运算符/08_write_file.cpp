#include <fstream>
#include <iostream>

int main()
{
    // 相对路径基于当前工作目录；此文件若已存在会被覆盖。
    std::ofstream out("course_numbers.txt");
    if (!out) {
        std::cerr << "Cannot open output file\n";
        return 1;
    }
    out << 10 << '\n' << 20.5 << '\n' << -3 << '\n';
    out.close();
    if (!out) {
        std::cerr << "Write or close failed\n";
        return 1;
    }
    std::cout << "Wrote course_numbers.txt\n";
}
