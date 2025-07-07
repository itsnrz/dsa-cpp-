#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> mp;

    // Insert elements
    mp[1] = "apple";
    mp[3] = "banana";
    mp[2] = "cherry";

    // Insert using insert()
    mp.insert({5, "mango"});
    mp.insert(make_pair(4, "orange"));

    // Access element
    cout << "Value at key 2: " << mp[2] << endl;

    // Traverse map (keys will be in sorted order)
    cout << "\nMap contents:\n";
    for (auto it : mp) {
        cout << "Key: " << it.first << ", Value: " << it.second << endl;
    }

    // Check if key exists
    int k = 3;
    if (mp.count(k))
        cout << "\nKey " << k << " exists with value: " << mp[k] << endl;
    else
        cout << "\nKey " << k << " does not exist\n";

    // Erase a key
    mp.erase(1);
    cout << "\nSize after erasing key 1: " << mp.size() << endl;

    // ✅ Check if value "banana" exists
    bool found = false;
    for (auto it : mp) {
        if (it.second == "banana") {
            found = true;
            break;
        }
    }
    if (found)
        cout << "banana is found\n";
    else
        cout << "banana is not found\n";

    return 0;
}
