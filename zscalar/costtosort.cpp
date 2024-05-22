#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minCostToSortArray(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp_asc(n, vector<int>(n));
    vector<vector<int>> dp_desc(n, vector<int>(n));
    vector<int> sorted_arr = arr;

    // Sort the array to get possible target values for ascending order
    sort(sorted_arr.begin(), sorted_arr.end());

    // Initialize dp_asc with the cost to change each element to each possible target value
    for (int j = 0; j < n; ++j) {
        dp_asc[0][j] = abs(arr[0] - sorted_arr[j]);
    }

    // Fill dp_asc with the minimum costs
    for (int i = 1; i < n; ++i) {
        int min_cost = INT_MAX;
        for (int j = 0; j < n; ++j) {
            min_cost = min(min_cost, dp_asc[i-1][j]);
            dp_asc[i][j] = min_cost + abs(arr[i] - sorted_arr[j]);
        }
    }

    // Sort the array in reverse to get possible target values for descending order
    reverse(sorted_arr.begin(), sorted_arr.end());

    // Initialize dp_desc with the cost to change each element to each possible target value
    for (int j = 0; j < n; ++j) {
        dp_desc[0][j] = abs(arr[0] - sorted_arr[j]);
    }

    // Fill dp_desc with the minimum costs
    for (int i = 1; i < n; ++i) {
        int min_cost = INT_MAX;
        for (int j = 0; j < n; ++j) {
            min_cost = min(min_cost, dp_desc[i-1][j]);
            dp_desc[i][j] = min_cost + abs(arr[i] - sorted_arr[j]);
        }
    }

    // Find the minimum cost to sort the entire array in ascending or descending order
    int min_cost = INT_MAX;
    for (int j = 0; j < n; ++j) {
        min_cost = min(min_cost, dp_asc[n-1][j]);
        min_cost = min(min_cost, dp_desc[n-1][j]);
    }

    return min_cost;
}

int main() {
    vector<int> arr = { 1, 2, 3, 3, 4};
    cout << "Minimum cost to sort array: " << minCostToSortArray(arr) << endl;
    return 0;
}
