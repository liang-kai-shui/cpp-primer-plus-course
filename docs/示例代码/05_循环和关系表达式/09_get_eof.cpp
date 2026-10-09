#include <cstddef>
#include <iostream>

int main()
{
    using Traits = std::char_traits<char>;
    Traits::int_type value;
    std::size_t count = 0;
    while ((value = std::cin.get()) != Traits::eof()) {
        char ch = Traits::to_char_type(value);
        std::cout.put(ch);
        ++count;
    }
    std::cout << "\ncharacters=" << count << '\n';
    if (std::cin.bad()) {
        std::cerr << "Read error\n";
        return 1;
    }
}
