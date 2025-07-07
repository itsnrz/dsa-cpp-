#include <iostream>
#include <vector>
#include <algorithm> // for sort, reverse, next_permutation
#include <bitset>    // optional, for binary representation
using namespace std;

bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second)return true;
    if(p1.second>p2.second) return false;
    if(p1.first<p1.first) return true;
    else return false;
}

int main() {
    // Create a vector of integers
    vector<int> v = {5, 2, 9, 1, 5, 6};

    // Original array
    cout << "Original array: ";
    for (int x : v) cout << x << " ";

    // Reverse the vector
    reverse(v.begin(), v.end());
    cout << "\nReversed vector: ";
    for (int x : v) cout << x << " ";

    // Next permutation
    if (next_permutation(v.begin(), v.end())) {
        cout << "\nNext permutation: ";
        for (int x : v) cout << x << " ";
    } else {
        cout << "\nNo next permutation exists (already last permutation)";
    }

    // Sort in ascending order (default)
    sort(v.begin(), v.end());
    cout << "\nSorted ascending: ";
    for (int x : v) cout << x << " ";

    // Sort in descending order using greater<int>()
    sort(v.begin(), v.end(), greater<int>());
    cout << "\nSorted descending (using greater<int>): ";
    for (int x : v) cout << x << " ";

    // Sort using lambda: even numbers before odd
    sort(v.begin(), v.end(), [](int a, int b) {
        return (a % 2 == 0 && b % 2 != 0) || (a % 2 == b % 2 && a < b);
    });
    cout << "\nSorted with even numbers first: ";
    for (int x : v) cout << x << " ";

    vector<pair<int ,int >>vec={{3,1},{2,2},{7,1},{5,2}};// vector of pair
    cout << "\n vector of pair is: ";
    for (auto x : vec) cout <<"("<< x.first << " "<<x.second<<")";// printing value of pairs
    sort(vec.begin(),vec.end());// sorting ascending
    cout << "\nSorted vector: ";
    for (auto x : vec) cout <<"("<< x.first << " "<<x.second<<")";
    sort(vec.begin(),vec.end(),comp);//custom comparator
    cout << "\nSorted vector(custom comparator): ";
    for (auto x : vec) cout <<"("<< x.first << " "<<x.second<<")";

    // ✅ ADDITIONAL FEATURES (DO NOT CHANGE EXISTING LOGIC)

    // Max and Min elements
    auto min_it = min_element(v.begin(), v.end());
    auto max_it = max_element(v.begin(), v.end());
    if (min_it != v.end() && max_it != v.end()) {
        cout << "\nMinimum element: " << *min_it;
        cout << "\nMaximum element: " << *max_it;
    }

    // Binary search: vector is sorted ascending before binary search
    sort(v.begin(), v.end()); // binary_search requires sorted data
    int target = 5;
    bool found = binary_search(v.begin(), v.end(), target);
    cout << "\nBinary search for " << target << ": " << (found ? "Found" : "Not Found");

    // Count set bits in an integer (e.g., 29 => 11101)
    int num = 29;
    int setBits = __builtin_popcount(num); // works for int
    cout << "\nNumber of set bits in " << num << ": " << setBits << endl;

    return 0;
}
