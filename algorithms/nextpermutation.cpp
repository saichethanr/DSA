#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3};

    cout << "Original vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // Generate the next permutation
    bool hasNext = next_permutation(vec.begin(), vec.end());

    if (hasNext) {
        cout << "Next permutation: ";
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "This is the last permutation." << endl;
        cout << "First permutation: ";
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Generate all permutations
    cout << "All permutations:" << endl;
    sort(vec.begin(), vec.end()); // Ensure starting from the first permutation
    do {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    } while (next_permutation(vec.begin(), vec.end()));

    return 0;
}
