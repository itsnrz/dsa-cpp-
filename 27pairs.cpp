#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    pair<int, string> p1 = {1, "apple"};
    pair<int, string> p2 = make_pair(2, "banana");

    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;

    // Swapping
    swap(p1, p2);
    cout << "After swap - p1: " << p1.first << ", " << p1.second << endl;

    // Array of pairs
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << "Array of pairs: ";
    for (auto p : arr)
        cout << "(" << p.first << "," << p.second << ") ";

    // Vector of pairs
    vector<pair<int, string>> vp;

    // Using push_back
    vp.push_back(make_pair(10, "ten"));          // requires make_pair
    vp.push_back({20, "twenty"});                // brace-initializer also OK

    // Using emplace_back (constructs in-place)
    vp.emplace_back(5, "five");                  // more efficient, directly constructs pair

    // Sort by first element
    sort(vp.begin(), vp.end());

    cout << "\n\nSorted vector of pairs:\n";
    for (auto pr : vp)
        cout << pr.first << " " << pr.second << endl;

    return 0;
}
