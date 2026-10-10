#include <iostream>
void subdivide(char ruler[], int left, int right, int depth);
int main()
{
    int depth = 0;
    if (!(std::cin >> depth) || depth < 0 || depth > 4) {
        std::cerr << "Expected depth 0..4\n";
        return 1;
    }
    char ruler[18];
    for (int i = 0; i < 17; ++i) ruler[i] = '.';
    ruler[0] = ruler[16] = '|';
    ruler[17] = '\0';
    subdivide(ruler, 0, 16, depth);
    std::cout << ruler << '\n';
}
void subdivide(char ruler[], int left, int right, int depth)
{
    if (depth <= 0 || right - left <= 1) return;
    int middle = left + (right - left) / 2;
    ruler[middle] = '|';
    subdivide(ruler, left, middle, depth - 1);
    subdivide(ruler, middle, right, depth - 1);
}
