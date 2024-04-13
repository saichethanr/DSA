#include <iostream>
#include <cctype>

int main() {
    char c = 'a'; // character to check

    if (std::isdigit(c)) {
        std::cout << "The character is a number." << std::endl;
    } else {
        std::cout << "The character is not a number." << std::endl;
    }

    return 0;
}
