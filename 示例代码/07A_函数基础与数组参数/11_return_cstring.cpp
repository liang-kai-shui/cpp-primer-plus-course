#include <iostream>
char* build_text(char symbol, int count);
int main()
{
    char symbol = '*';
    int count = 0;
    if (!(std::cin >> symbol >> count) || count < 0 || count > 80) {
        std::cerr << "Expected one character and count 0..80\n";
        return 1;
    }
    char* text = build_text(symbol, count);
    std::cout << '[' << text << "]\n";
    delete[] text; // 返回的地址对应new[]，调用方在用完后释放。
}
char* build_text(char symbol, int count)
{
    char* text = new char[count + 1];
    for (int i = 0; i < count; ++i) text[i] = symbol;
    text[count] = '\0';
    return text;
}
