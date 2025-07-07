#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    deque<int> dq;
    deque<int> dq1(5, -1);   // 5 elements initialized to -1
    deque<int> dq2(dq1);     // copy constructor

    // Print dq1 and dq2
    cout << "\ndq1: ";
    for (int x : dq1) cout << x << " ";

    cout << "\ndq2 (copy): ";
    for (int x : dq2) cout << x << " ";

    // Add elements
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);

    cout << "\n\nSize: " << dq.size();
    cout << "\nFront: " << dq.front();
    cout << "\nBack: " << dq.back();
    cout << "\nElement at index 2: " << dq[2] << ", using at(): " << dq.at(2);

    // Iterate using iterator
    cout << "\n\nDeque using iterator: ";
    for (deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
        cout << *it << " ";

    // Reverse iterate with auto
    cout << "\nDeque in reverse using auto: ";
    for (auto rit = dq.rbegin(); rit != dq.rend(); ++rit)
        cout << *rit << " ";

    // Pop front and back
    dq.pop_back();  // removes 20
    dq.pop_front(); // removes 1

    cout << "\nAfter pop_back and pop_front: ";
    for (int x : dq) cout << x << " ";

    // Sort (must use random access iterators)
    sort(dq.begin(), dq.end());

    cout << "\nSorted deque: ";
    for (int x : dq) cout << x << " ";

    // Clear deque
    dq.clear();
    cout << "\nDeque cleared. Size: " << dq.size() << "\n";
}
