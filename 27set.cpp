#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // Insert elements
    s.insert(50);
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(10);  // duplicate, will not be added

    cout << "Set elements (sorted & unique): ";
    for (int x : s) {
        cout << x << " ";
    }

    // Check if an element exists
    int key = 30;
    if (s.count(key))
        cout << "\n" << key << " exists in the set.";
    else
        cout << "\n" << key << " does not exist.";

    // Erase an element
    s.erase(10);
    cout << "\nAfter erasing 10: ";
    for (int x : s)
        cout << x << " ";

    // Find and print using iterator
    auto it = s.find(20);
    if (it != s.end())
        cout << "\nElement found using find(): " << *it << endl;
    else
        cout << "\nElement not found\n";

    // 🔽 Lower Bound and Upper Bound
    int lb_key = 25, ub_key = 30;

    auto lb = s.lower_bound(lb_key);  // first element >= 25
    auto ub = s.upper_bound(ub_key);  // first element > 30

    cout << "\n\nLower bound of " << lb_key << ": ";
    if (lb != s.end())
        cout << *lb;
    else
        cout << "No element ≥ " << lb_key;

    cout << "\nUpper bound of " << ub_key << ": ";
    if (ub != s.end())
        cout << *ub;
    else
        cout << "No element > " << ub_key;

    cout << endl;
    return 0;
}
