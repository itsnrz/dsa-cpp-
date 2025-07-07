#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Max-Heap: default priority_queue (largest element at top)
    priority_queue<int> maxHeap;

    // Min-Heap: smallest element at top
    priority_queue<int, vector<int>, greater<int>> minHeap;// greater int is functor (function object)

    // Add same elements to both heaps
    vector<int> elements = {10, 30, 20, 40};

    for (int x : elements) {
        maxHeap.push(x);
        minHeap.push(x);
    }

    // Display max-heap
    cout << "Max-Heap (default): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    // Display min-heap
    cout << "\nMin-Heap: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}
