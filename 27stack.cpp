#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    // Push elements into first stack
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // 30
    cout << "Size: " << st.size() << endl;       // 3

    // Pop top
    st.pop();  // removes 30
    cout << "After pop, top: " << st.top() << endl; // 20

    // Add using emplace
    st.emplace(40);  // now st = {10, 20, 40}

    // Create another stack
    stack<int> st2;
    st2.push(1);
    st2.push(2);  // st2 = {1, 2}

    // Display both stacks before swap
    cout << "\nBefore swap:";
    cout << "\nTop of st: " << st.top();   // 40
    cout << "\nTop of st2: " << st2.top(); // 2

    // Swap contents
    st.swap(st2);

    // Display both stacks after swap
    cout << "\n\nAfter swap:";
    cout << "\nTop of st: " << st.top();   // 2 (from st2)
    cout << "\nTop of st2: " << st2.top(); // 40 (from st)

    // Print all elements of swapped stack st
    cout << "\n\nStack st elements (after swap): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << "\nStack is now empty: " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}
