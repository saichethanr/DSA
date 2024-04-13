#include <iostream>
#include <cctype>
using namespace std;
int main() {
    char c = '7'; // character to check
    int num = c-'0';
    cout<<num<<endl;
    if (std::isdigit(c)) {
        std::cout << "The character is a number." << std::endl;
    } else {
        std::cout << "The character is not a number." << std::endl;
    }

    return 0;
}
