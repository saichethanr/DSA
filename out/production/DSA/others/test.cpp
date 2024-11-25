#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findTotalCost(vector<int> arr) {
    int total_cost = 0;
    if (arr.size() <= 1) {
        return 0;
    }
    sort(arr.begin(),arr.end());
    int s = 0; 
    int e = arr.size() - 1; 
    while (s < e) {
        int minel = arr[s];
        int maxel = arr[e];

        int den = maxel-minel;
        int cost = ceil((minel + maxel) / (den + 1.0));
        total_cost+=cost;

        s++;
        arr[e] = minel+maxel;
    }

    return total_cost;
}

int main() {
    vector<int> v = {1,2,3,4};
    int ans = findTotalCost(v);
    if (ans == -1) {
        cout << "Error occurred." << endl;
    } else {
        cout << "Total cost: " << ans << endl;
    }
 
    return 0;
}
