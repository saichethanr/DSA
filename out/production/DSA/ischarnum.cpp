#include <iostream>
#include <cctype>
using namespace std;
int main() {
    char c = 'c'; // character to check
    int num = c-'a';
    cout<<num<<endl;
    if (std::isdigit(c)) {
        std::cout << "The character is a number." << std::endl;
    } else {
        std::cout << "The character is not a number." << std::endl;
    }

    return 0;
}
