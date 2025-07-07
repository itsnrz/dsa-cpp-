#include <iostream>
#include <list>
#include <algorithm> // for sort()
using namespace std;

int main() {
    list<int> l;
    list<int> list1(5, -1); // 5 elements, all -1
    list<int> list2(list1); // copy constructor

    // Print list1 and list2
    cout << "\nlist1: ";
    for (int x : list1) cout << x << " ";

    cout << "\nlist2 (copy): ";
    for (int x : list2) cout << x << " ";

    // Add elements to list
    l.push_back(10);
    l.emplace_back(20);
    l.push_back(30);
    l.push_front(5);

    cout << "\n\nSize: " << l.size();
    cout << "\nFirst (front): " << l.front();
    cout << "\nLast (back): " << l.back();

    // Using iterator
    list<int>::iterator it = l.begin();
    advance(it, 2);  // move to 3rd element
    cout << "\n\nElement at 3rd position using iterator: " << *it;

    // Print using iterator
    cout << "\n\nList using iterator: ";
    for (list<int>::iterator itr = l.begin(); itr != l.end(); ++itr)
        cout << *itr << " ";

    // Reverse iterator
    cout << "\nList in reverse using reverse_iterator: ";
    for (list<int>::reverse_iterator rit = l.rbegin(); rit != l.rend(); ++rit)
        cout << *rit << " ";

    // Using auto for reverse iterator
    cout << "\nList using reverse iterator with auto: ";
    for (auto revIt = l.rbegin(); revIt != l.rend(); ++revIt)
        cout << *revIt << " ";

    // Remove an element (all occurrences)
    l.remove(20); // removes all 20s

    cout << "\n\nAfter remove(20): ";
    for (auto x : l) cout << x << " ";

    // Sort the list
    l.sort();
    cout << "\nSorted list: ";
    for (auto x : l) cout << x << " ";

    // Reverse the list
    l.reverse();
    cout << "\nReversed list: ";
    for (auto x : l) cout << x << " ";
     
    //poping element from back
    l.pop_back();
    cout<<"\nlist element after poping one from back : ";
    for(int val:l)cout<<val<<" ";

    //poping element from front
    l.pop_front();
    cout<<"\nlist element after poping one from front : ";
    for(int val:l)cout<<val<<" ";
    
    // Clear the list
    l.clear();
    cout << "\nList cleared. Size now: " << l.size() << "\n";
}
