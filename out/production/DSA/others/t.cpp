#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solvesai(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> h(nums.begin(), nums.end());
    int totalCost = 0;
    while (h.size() > 1) {
        int smallest1 = h.top();
        h.pop();
        int smallest2 = h.top();
        h.pop();
        
        int cost = smallest1 + smallest2;
        totalCost += cost;
        h.push(cost);
    }
    
    return totalCost;
}

int main() {
    vector<int> array = {25, 10, 20};
    int result = solvesai(array);
    cout << "Minimum possible cost to reduce the array: " << result << endl;
    return 0;
}
