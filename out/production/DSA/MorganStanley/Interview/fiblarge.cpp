#include <iostream>
#include <vector>
using namespace std;

// Function to add two large numbers
vector<int> addLargeNumbers(const vector<int> &a, const vector<int> &b) {
    vector<int> result;
    int carry = 0, sum;
    int aSize = a.size(), bSize = b.size();
    
    for (int i = 0; i < max(aSize, bSize) || carry; i++) {
        sum = carry;
        if (i < aSize) sum += a[i];
        if (i < bSize) sum += b[i];
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    
    return result;
}

// Function to print a large number
void printLargeNumber(const vector<int> &number) {
    for (int i = number.size() - 1; i >= 0; i--) {
        cout << number[i];
    }
    cout << endl;
}

// Function to generate the first 1000 Fibonacci numbers
void generateFibonacci(int n) {
    vector<int> a = {0}; // F(0)
    vector<int> b = {1}; // F(1)

    if (n >= 1) printLargeNumber(a);
    if (n >= 2) printLargeNumber(b);

    for (int i = 3; i <= n; i++) {
        vector<int> next = addLargeNumbers(a, b);
        printLargeNumber(next);
        a = b;
        b = next;
    }
}

int main() {
    int n = 18;
    generateFibonacci(n);
    return 0;
}