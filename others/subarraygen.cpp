#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateSubarrays(const vector<int>& arr) {
    vector<vector<int>> subarrays;
    int n = arr.size();
    
    for (int i = 0; i < n; ++i) {
        vector<int> subarray;
        for (int j = i; j < n; ++j) {
            subarray.push_back(arr[j]);
            subarrays.push_back(subarray);
        }
    }
    
    return subarrays;
}

int main() {
    vector<int> arr = {1,3,1,2,2};
    vector<vector<int>> subarrays = generateSubarrays(arr);
    for (const auto& subarray : subarrays) {
        for (int num : subarray) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
