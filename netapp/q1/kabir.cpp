#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate GCD of a vector of numbers
int findGCD(const vector<int>& nums) {
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        result = gcd(result, nums[i]);
        if (result == 1) {
            return 1; // Early exit if GCD becomes 1
        }
    }
    return result;
}

bool canSplitIntoTwoSets(vector<int>& nums) {
    int n = nums.size();
    vector<int> subset1, subset2;
    
    for (int i = 0; i < n; ++i) {
        if (nums[i] > 17) {
            if (subset1.size() < n / 2) {
                subset1.push_back(nums[i]);
            } else if (subset2.size() < n / 2) {
                subset2.push_back(nums[i]);
            }
        }
    }
    
    if (subset1.size() == n / 2 && subset2.size() == n / 2) {
        int gcd1 = findGCD(subset1);
        int gcd2 = findGCD(subset2);
        return gcd1 > 17 && gcd2 > 17;
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        if (canSplitIntoTwoSets(nums)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
