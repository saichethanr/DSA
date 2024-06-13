#include <iostream>
#include <vector>
using namespace std;

void multiply(vector<int> &number, int x) {
    int carry = 0;
    for (int i = 0; i < number.size(); i++) {
        int prod = number[i] * x + carry;
        number[i] = prod % 10;
        carry = prod / 10;
    }
    
    while (carry) {
        number.push_back(carry % 10);
        carry /= 10;
    }
}

void factorial(int n) {
    vector<int> result;
    result.push_back(1);
    
    for (int i = 2; i <= n; i++) {
        multiply(result, i);
    }

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
}

int main() {
    int n = 90;
    factorial(n);
    return 0;
}