#include <iostream>

int main()
{
    bool running = true;
    char command;
    std::cout << "c=continue p=progress q=quit\n";
    while (running && (std::cin >> command)) {
        switch (command) {
        case 'c':
        case 'C':
            std::cout << "Continue studying\n";
            break;
        case 'p':
        case 'P':
            std::cout << "Record your own progress\n";
            break;
        case 'q':
        case 'Q':
            running = false; // break 只离开 switch；这个标志结束外层 while。
            std::cout << "Bye\n";
            break;
        default:
            std::cout << "Unknown command\n";
            break;
        }
    }
}
