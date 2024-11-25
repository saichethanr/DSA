#include <iostream>
#include <queue>
using namespace std;
int main() {
    priority_queue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.push(15);
    
    std::cout << "Top element: " << pq.top() << std::endl; // Outputs 15
    
    pq.pop();
    
    std::cout << "Top element after pop: " << pq.top() << std::endl; // Outputs 10
    
    return 0;
}
