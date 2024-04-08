#include <iostream>
#include <queue>
using namespace std;
int main() {
    priority_queue<pair<int,int>> pq;
    pq.push({1,3});
    pq.push({2,1});

    
   cout << "Top element: " << pq.top().first << endl; // Outputs 15
    
    pq.pop();
    
    std::cout << "Top element after pop: " << pq.top().first << std::endl; // Outputs 10
    
    return 0;
}