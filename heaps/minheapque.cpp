#include <iostream>
#include <queue>
using namespace std;
int main() {
    priority_queue<int, vector<int>, greater<int>> minHeapPQ;
    
    minHeapPQ.push(10);
    minHeapPQ.push(5);
    minHeapPQ.push(15);
    
    std::cout << "Top element: " << minHeapPQ.top() << std::endl; // Outputs 5
    
    minHeapPQ.pop();
    
    std::cout << "Top element after pop: " << minHeapPQ.top() << std::endl; // Outputs 10
    
    return 0;
}
