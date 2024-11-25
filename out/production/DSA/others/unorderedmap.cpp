#include<bits/stdc++.h> 

using namespace std;
int main() {
    vector<int> array = {50, 20, 40, 10, 30};
    map<int, int> unorderedMap;
    for (int i = 0; i < array.size(); ++i) {
        unorderedMap[array[i]]++;
    }
    cout << "Unordered map contents:" << endl;
    for (const auto& pair : unorderedMap) {
        std::cout << "Index: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    return 0;
}
