#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Add elements
    q.push(10);
    q.push(20);
    q.emplace(30);  // same as push but more efficient for complex types

    cout << "Front: " << q.front() << endl; // 10
    cout << "Back: " << q.back() << endl;   // 30
    cout << "Size: " << q.size() << endl;   // 3

    // ❗ Demonstrating q.front() + 1
    cout << "q.front() + 1: " << q.front() + 1 << " (Note: this is NOT the second element, just front + 1)" << endl;

    // Pop front
    q.pop();  // removes 10
    cout << "After pop, new front: " << q.front() << endl; // 20

    // Display queue elements
    cout << "\nQueue elements (FIFO): ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << "\nQueue is now empty: " << (q.empty() ? "Yes" : "No") << endl;

    // Swap example
    queue<int> q1, q2;
    q1.push(1); q1.push(2);
    q2.push(100); q2.push(200);

    q1.swap(q2);
    cout << "\nAfter swap, q1 front: " << q1.front() << ", q2 front: " << q2.front() << endl;

    return 0;
}
