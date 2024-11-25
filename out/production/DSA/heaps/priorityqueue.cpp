#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Create a priority queue of integers
    priority_queue<int> pq;

    // Insert elements into the priority queue
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(30);

    // Print the size of the priority queue
    cout << "Size of priority queue: " << pq.size() << endl;

    // Print and remove elements from the priority queue
    while (!pq.empty()) {
        cout << pq.top() << " ";  // Print the highest priority element
        pq.pop();                 // Remove the highest priority element
    }

    cout << endl;

    return 0;
}
