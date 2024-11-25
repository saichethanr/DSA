// You are given a set of pair of integers (a,b) (a,b>0). The pair represents the floor numberof a building which is present in left and right side of the street. Now, count the number of intersecting points if line is drawn between each pair of integers.

// Sample input 1:
// 1 1
// 2 2
// 3 4
// Output 1:
// 0
// There is no intersection between the pairs (1,1) and (2,2) and (3,4)

// Sample input 2:
// 1 3
// 2 2
// 3 4
// Output 2:
// 1
// Here, the line between (1,3) will cross the line (2,2), So output is 1 in this case.

// Sample input 3:
// 1 1
// 2 2
// 3 3
// 1 3
// Output 3:
// 3
// Here the line between (1,3) will cross the lines (1,1), (2,2) and (3,3). So the number of intersecting points is 3.
#include<bits/stdc++.h> 
using namespace std;

int solve(const vector<pair<int, int>>& b) {
    int cnt = 0;
    for (int  i = 0; i < b.size(); ++i) {
        for (int j = i; j < b.size(); ++j) {
            if ((b[i].first <= b[j].first && b[i].second >= b[j].second) ||
                (b[i].first >= b[j].first && b[i].second <= b[j].second) || (b[i].first==b[j].first && b[i].second!=b[j].second)|| (b[i].second==b[j].second && b[i].second!=b[j].second)) {
                cnt++;
            }
        }
    }
    return cnt;
}


int main() {
    // Sample input 1:
    vector<pair<int, int>> buildings1 = {{1, 1}, {2, 2}, {3, 4}};
    cout << "Output 1: " << solve(buildings1) << endl;
    

    // Sample input 2:
    vector<pair<int, int>> buildings2 = {{1, 3}, {2, 2}, {3, 4}};
    cout << "Output 2: " << solve(buildings2) << endl;

    // Sample input 3:
    vector<pair<int, int>> buildings3 = {{1, 1}, {2, 2}, {3, 3}, {1, 3}};
    cout << "Output 3: " << solve(buildings3) << endl;

    return 0;
}