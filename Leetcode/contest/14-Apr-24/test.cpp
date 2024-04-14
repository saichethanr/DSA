#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int kthSmallestAmount(vector<int>& coins, int k) {
    int n = coins.size();
    vector<int> dp(k + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= k; ++j) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    return dp[k] == INT_MAX ? -1 : dp[k];
}

int main() {
    // Example 1
    vector<int> coins1 = {3, 6, 9};
    int k1 = 3;
    cout << "Example 1 Output: " << kthSmallestAmount(coins1, k1) << endl;  // Output: 9

    // Example 2
    vector<int> coins2 = {5, 2};
    int k2 = 7;
    cout << "Example 2 Output: " << kthSmallestAmount(coins2, k2) << endl;  // Output: 12

    return 0;
}
