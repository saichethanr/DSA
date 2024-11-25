#include <iostream>
#include <string>

using namespace std;

string leftRotateString(const string& str, int d) {
    int n = str.length();
    // Handle the case where rotation amount is greater than string length
    d = d % n;
    // Concatenate the substring from index d to the end of the string with the substring from index 0 to d
    return str.substr(d) + str.substr(0, d);
}

int main() {
    string str = "HelloWorld";

    int rotateAmount = 1; // Number of positions to rotate left
    string rotatedString = leftRotateString(str, rotateAmount);

    cout << "Original string: " << str << endl;
    cout << "Left rotated string: " << rotatedString << endl;

    return 0;
}
