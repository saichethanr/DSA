#include <iostream>

int cyclic_distance(char char1, char char2) {
    const int alphabet_size = 26;
    int distance = std::abs(char2 - char1);

   
    if (distance > alphabet_size / 2)
        distance = alphabet_size - distance;

    return distance;
}

int main() {
    char char1 = 's';
    char char2 = 'a';

    std::cout << "Cyclic distance between '" << char1 << "' and '" << char2 << "' in the alphabet cycle: ";
    std::cout << cyclic_distance(char1, char2) << std::endl;

    return 0;
}
