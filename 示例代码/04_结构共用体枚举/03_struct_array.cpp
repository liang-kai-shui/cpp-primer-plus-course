// ============================================================
//  L05 · 示例 3：结构数组        （教材 4.4.5, p110-111）
// ------------------------------------------------------------
//  「结构」和「数组」可以叠加：
//     数组      = 把【同类型】的多个数据排成一排
//     结构      = 把【不同类型】的数据打包成一个
//     结构数组  = 每个元素都是一个结构 —— 天然的「表格」
// ============================================================
#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int         age;
    double      score;
};

int main()
{
    using namespace std;

    // ---------- 声明并初始化：每个元素是一层 {..} ----------
    Student group[3] = {
        {"Li Ming",   19, 92.5},
        {"Wang Fang", 20, 88.0},
        {"Zhang Wei", 18, 95.5},
    };

    // ---------- 遍历：像访问一张表格 ----------
    cout << "姓名\t\t年龄\t成绩\n";
    cout << "--------------------------------\n";
    for (int i = 0; i < 3; ++i)
    {
        cout << group[i].name << "\t\t" << group[i].age << "\t" << group[i].score << "\n";
    }
    cout << "  ^ group[i] 是第 i 个结构，再 .name 取它的成员 —— 「先下标，再点」\n";

    // ---------- 求平均分 ----------
    double sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        sum += group[i].score;
    }
    cout << "\n平均分: " << sum / 3 << "\n";

    // ---------- 找最高分 ----------
    int best = 0;                                   // 先假设第 0 个最高
    for (int i = 1; i < 3; ++i)
    {
        if (group[i].score > group[best].score)
            best = i;                               // 发现更高的就换
    }
    cout << "最高分: " << group[best].name << " (" << group[best].score << ")\n";

    // ---------- 修改某个元素 ----------
    group[1].score = 90.0;                          // 给王芳加分
    cout << "\n改过之后 group[1].score = " << group[1].score << "\n";

    // ---------- 元素之间可以整体赋值 ----------
    group[0] = group[2];
    cout << "group[0] = group[2]; 之后 group[0].name = " << group[0].name << "\n";

    return 0;
}
