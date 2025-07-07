#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    vector<int> vec(10, -1);
    vector<int> vec2(vec);

    // Print vec and vec2
    cout << "\nvec: ";
    for (int x : vec) cout << x << " ";

    cout << "\nvec2 (copy): ";
    for (int x : vec2) cout << x << " ";

    // Add elements to vector v
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "\n\nSize: " << v.size();
    cout << "\nFirst: " << v.front();
    cout << "\nLast: " << v.back();
    cout << "\nv.at(2) and v[2]: " << v.at(2) << " " << v[2];

    // Iterator basics
    vector<int>::iterator it = v.begin();
    cout << "\n\nUsing iterator:";
    cout << "\n*begin(): " << *it;           // points to 10
    cout << "\n*(begin() + 1): " << *(it + 1); // points to 20
    cout << "\n*(end() - 1): " << *(v.end() - 1); // last element, 30

    // 🚫 Dereferencing end() directly — invalid:
    cout << "\n\nDereferencing v.end() (🚫 invalid): ";
    // cout << *v.end(); // ❌ Uncommenting this will lead to undefined behavior (garbage or crash)

    cout << "\nNote: v.end() points one past the last element — never dereference it!\n";

    // Print using iterator in for loop
    cout << "\nVector v using iterator in for loop: ";
    for (vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr)
        cout << *itr << " ";  // 10 20 30

    // 🔁 Print using reverse iterator
    cout << "\nVector v using reverse iterator: ";
    for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit)
        cout << *rit << " ";  // 30 20 10

    // 🔁 Reverse iterator using auto
    cout << "\nVector v using reverse iterator with auto: ";
    for (auto revIt = v.rbegin(); revIt != v.rend(); ++revIt)
        cout << *revIt << " ";  // 30 20 10

    // Pop and print again
    v.pop_back(); // removes 30
    cout << "\nAfter pop_back(): ";
    for (auto iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << " ";  // 10 20

    // Sort and clear
    sort(v.begin(), v.end());
    v.clear(); // removes all elements

    cout << "\nVector cleared. Size now: " << v.size() << "\n";
}
