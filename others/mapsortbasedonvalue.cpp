#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Comparator function to sort pairs by their second element (value)
bool sortByValue(const pair<char, int> &a, const pair<char, int> &b) {
    return a.second < b.second; // '>' for descending order, '<' for ascending order
}

int main() {
    // Sample map
    map<char, int> teamScores = {
        {'A', 0},
        {'B', 8},
        {'C', 7},
    };

    // Copy map contents to a vector of pairs
    vector<pair<char, int>> vec(teamScores.begin(), teamScores.end());

    // Sort the vector based on the value (second element of pair)
    sort(vec.begin(), vec.end(), sortByValue);
    // Output the sorted vector
    for (const auto &p : vec) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
