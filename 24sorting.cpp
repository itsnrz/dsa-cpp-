/*🧠 Bubble Sort – Intuition :
Bubble Sort works just like bubbling up larger elements to the top, pass by pass — that's why it's called "Bubble" Sort.
🔁 Core Idea:
    Compare each adjacent pair of elements.
    If they're in the wrong order, swap them.
    After each full pass, the largest unsorted element moves to its correct position at the end.
    Repeat this process for the rest of the array, ignoring the sorted portion at the end.

🧩 Mental Picture:

    Imagine bubbles (big numbers) rising to the surface (end of the array).

    In every pass, you push the largest unsorted element to the end by repeatedly swapping with the neighbor.


🚦 Optimization:

    If no swaps happen in a pass, the array is already sorted → stop early. (This is where isswap = false comes in.)


🕰️ Time Complexity:

    Best case (already sorted): O(n) (with optimization)

    Average and Worst case: O(n²)

    Space: O(1) (in-place)
*/




/*🧠 Selection Sort – Intuition (Without Example)
Selection Sort works like selecting the best (smallest) candidate from a list of unsorted values and placing it in the correct position.
🔁 Core Idea:
    Divide the array into two parts:

        The sorted part on the left (initially empty)

        The unsorted part on the right (initially the entire array)
    In each pass:

        Find the smallest element in the unsorted part.

        Swap it with the leftmost unsorted element.

        Expand the sorted section by one.


🧩 Mental Picture:
    Imagine you're picking the smallest item from a basket and placing it in order on a shelf.
    With each pass, the minimum element "gets selected" and placed at its rightful position in the array.


🔧 Optimization Note:

    You can avoid unnecessary swaps by only swapping if the smallest element isn’t already at the current index.


🕰️ Time Complexity:

    Best, Average, and Worst Case: O(n²) (comparison-heavy)

    Space: O(1) (in-place)

*/




/*🧠 Insertion Sort – Intuition :
Insertion Sort mimics the way we organize cards in our hands while playing.
🔁 Core Idea:

    Start from the second element, assuming the first one is already "sorted."
    Pick one element at a time (called the "key") and insert it into its correct position within the sorted part on the left.
    Keep expanding the sorted section one element at a time.

🧩 Mental Model:

    Think of a growing sorted section on the left side.

    Each new element from the right is compared backwards with elements in the sorted section.

    You shift larger elements one step right to make space.

    Place the key where it fits correctly.

    Repeat until the entire array is sorted.


🕰️ Time Efficiency:

    Best case (already sorted): O(n)

    Worst case (reversed): O(n²)

    Space: O(1) (in-place)

*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> insertionsort(vector<int>a){
    int s=a.size();
    for(int i=1;i<s;i++){
        int curr=a[i];
        int prev=i-1;
        while(prev>=0&&a[prev]>curr){
            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=curr;
    }
    return a;
}
vector<int> selectionsort(vector<int>a){
    int s=a.size();
    for(int i=0;i<s-1;i++){
        int small=i;
        for(int j=i+1;j<s;j++){
            if(a[small]>a[j])small=j;
        }
        if(small!=i) swap(a[i],a[small]); // it means we have find element smaller than i
    }
    return a;
}
vector<int> bubblesort(vector<int>a){//O(n^2)
    int s=a.size();
    for(int i=0;i<s-1;i++){
        bool isswap=false;
        for(int j=0;j<s-i-1;j++){
            if(a[j]>a[j+1]){ 
               swap(a[j],a[j+1]);
               isswap=true;
            }
        }
        if(!isswap) return a;// array is already sorted as value of is swap is false and !isswap becomes true
    }
    return a;
}
int main() {
    vector<int> a = {4, 1, 5, 2, 3};

    cout << "elements before swaping : ";
    for (int val : a) cout << val << " ";

    cout << "\nelements after swaping(bubble sort) : ";
    vector<int>b=bubblesort(a);
    for (int val : b) cout << val << " ";

    cout << "\nelements before swaping : ";
    for (int val : a) cout << val << " ";

    cout << "\nelements after swaping(selection sort) : ";
    vector<int>c=selectionsort(a);
    for (int val : c) cout << val << " ";


    cout << "\nelements before swaping : ";
    for (int val : a) cout << val << " ";

    cout << "\nelements after swaping(insertion sort) : ";
    vector<int>d=insertionsort(a);
    for (int val : d) cout << val << " ";
}