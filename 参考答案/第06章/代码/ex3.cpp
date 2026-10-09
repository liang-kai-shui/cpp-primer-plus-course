#include <iostream>

int main()
{
    bool running = true;
    char command;
    std::cout << "c=course p=progress t=tip g=greeting q=quit\n";
    while (running && (std::cin >> command)) {
        switch (command) {
        case 'c': case 'C': std::cout << "C++ course\n"; break;
        case 'p': case 'P': std::cout << "Record your progress\n"; break;
        case 't': case 'T': std::cout << "Test boundary inputs\n"; break;
        case 'g': case 'G': std::cout << "Hello\n"; break;
        case 'q': case 'Q': running = false; std::cout << "Bye\n"; break;
        default: std::cout << "Unknown command\n"; break;
        }
    }
}
