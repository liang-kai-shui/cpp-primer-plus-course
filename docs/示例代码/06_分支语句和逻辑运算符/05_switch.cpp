#include <iostream>

int main()
{
    enum Action { Continue, Progress, Quit, Unknown };
    bool running = true;
    char command;
    std::cout << "c=continue p=progress q=quit\n";
    while (running && (std::cin >> command)) {
        Action action = Unknown;
        switch (command) {
        case 'c': case 'C': action = Continue; break;
        case 'p': case 'P': action = Progress; break;
        case 'q': case 'Q': action = Quit; break;
        default: break;
        }
        switch (action) {
        case Continue: std::cout << "Continue studying\n"; break;
        case Progress: std::cout << "Record your own progress\n"; break;
        case Quit: running = false; std::cout << "Bye\n"; break;
        default: std::cout << "Unknown command\n"; break;
        }
    }
}
