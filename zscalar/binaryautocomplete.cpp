#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<string> vec) {
    map<pair<int, int>, int> um;
    vector<int> res;

    for (int i = 0; i < vec.size(); i++) {
        int a = 0;
        int index = i;
        for (int j = 0; j < vec[i].length(); j++) {
            a = a * 2 + vec[i][j] - '0';
            if (um.find({a, j + 1}) != um.end())
                index = um[{a, j + 1}] + 1;
            um[{a, j + 1}] = i;
        }
        res.push_back(index);
    }
    
    return res;
}

int main() {
    vector<string> vec = {"000", "1110", "01", "001", "110", "11"};
    vector<int> res = solve(vec);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
}
