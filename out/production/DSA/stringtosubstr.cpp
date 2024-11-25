#include <iostream>
#include <string>
using namespace std;

int main() {
    // Given string
    string s = "examplestring";
    
    // Index l (inclusive) and r (exclusive)
    int l = 2;
    int r = 6;
    
    // Creating substring using substr function
    string substring = s.substr(l, r - l);
    
    cout << substring << endl; // Output: "ampl"
    
    return 0;
}
