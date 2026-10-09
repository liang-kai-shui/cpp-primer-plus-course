#include <iostream>

int main()
{
    int low, high;
    if (!(std::cin >> low >> high) || low < -100000 || high > 100000 || low > high) {
        std::cerr << "Invalid range\n";
        return 1;
    }
    long long sum = 0;
    for (int n = low; n <= high; ++n) sum += n;
    std::cout << "sum=" << sum << '\n';
}
