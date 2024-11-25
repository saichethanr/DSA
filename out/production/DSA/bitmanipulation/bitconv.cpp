#include <bitset>
#include <iostream>
using namespace std;

int main() {
    int number = 42;
    bitset<32> binaryRepresentation(number);
    cout << "Binary representation of " << number << ": " << binaryRepresentation << std::endl;
    return 0;
}
