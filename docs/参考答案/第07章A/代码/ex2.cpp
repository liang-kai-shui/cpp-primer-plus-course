#include <cmath>
#include <iostream>
int fill_scores(double scores[], int capacity);
void show_scores(const double scores[], int count);
double mean_score(const double scores[], int count);
int main()
{
    double scores[10]{};
    int count = fill_scores(scores, 10);
    if (count < 0) return 1;
    show_scores(scores, count);
    if (count == 0) std::cout << "No scores\n";
    else std::cout << "mean=" << mean_score(scores, count) << '\n';
}
int fill_scores(double scores[], int capacity)
{
    int count = 0;
    double score = 0;
    while (count < capacity && (std::cin >> score)) {
        if (!std::isfinite(score) || score < 0 || score > 1000) {
            std::cerr << "Expected finite score 0..1000\n";
            return -1;
        }
        scores[count++] = score;
    }
    return count;
}
void show_scores(const double scores[], int count)
{
    std::cout << "count=" << count << " scores:";
    for (int i = 0; i < count; ++i) std::cout << ' ' << scores[i];
    std::cout << '\n';
}
double mean_score(const double scores[], int count)
{
    double total = 0;
    for (int i = 0; i < count; ++i) total += scores[i];
    return total / count; // 调用前已保证count>0。
}
