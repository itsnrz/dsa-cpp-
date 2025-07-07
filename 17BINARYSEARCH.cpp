/*🔍 Definition: Binary Search

Binary Search is an efficient search algorithm used to find the 
position of a target element within a sorted array (ascending or descending).
It works by repeatedly dividing the search interval in half and eliminating
 half of the elements each time.*/



/*🧠 How It Works (Step-by-Step)

Given:

    A sorted array arr[]

    A target value x

Steps:

    1 = Set two pointers: low = 0, high = n - 1

    2 = While low <= high:

        Find the middle: mid = low + (high - low) / 2

        If arr[mid] == x, return mid (element found)

        If arr[mid] < x, search in the right half (low = mid + 1)

        If arr[mid] > x, search in the left half (high = mid - 1)

    3 = If not found, return -1
*/


/*✅ Conditions for Applying Binary Search
Condition                      	 Requirement
🔢 Sorted Data	                The array or data structure must be sorted in ascending or descending order.
🧮 Random Access	            The structure should allow constant time access (like arrays or vectors).
🚫 No Duplicates (optional)  	Not mandatory, but simplifies logic in some variants.*/


/*
#include<iostream>
#include<vector>
using namespace std;
int binaryitrea(vector<int>a,int t){//iterative code
int s=0,e=a.size()-1;
int mid=0;
while(s<=e){
    mid=s+(e-s)/2;    //mid=(s+e)/2 in large input this can give buffer overflow hence this formula is not used
    if(a[mid]<t)s=mid+1;
    else if(a[mid]>t)e=mid-1;
    else return mid;
    
}
return -1;
}
int binaryrec(vector<int>a,int t,int s,int e){//recursive
int mid=s+(e-s)/2;
if(s>e)return-1;
else if(a[mid]<t )return binaryrec(a,t,mid+1,e);
else if(a[mid]>t)return binaryrec(a,t,s,mid-1);
else  return mid;
}
int main(){
    vector<int>a1={-1,0,3,4,5,9,12};
    int t1=12;
    vector<int>a2={-1,0,3,5,9,12};
    int t2=12;
    cout<<"\n\t\t\t iterative approach"<<endl;
    cout<<"result of binary search(a1) : "<<binaryitrea(a1,t1)<<endl;
    cout<<"result of binary search(a2) : "<<binaryitrea(a2,t2)<<endl;
    cout<<"\n\t\t\t recursive approach"<<endl;
    int s=0,e=a1.size()-1;
    cout<<"result of binary search(a1) : "<<binaryrec(a1,t1,s,e)<<endl;
    s=0,e=a2.size()-1;
    cout<<"result of binary search(a2) : "<<binaryrec(a2,t2,s,e)<<endl;
    return 0;
}
*/


#include<iostream>
#include<vector>
using namespace std;

// Iterative implementation of binary search
int binaryitrea(vector<int> a, int t) {
    int s = 0, e = a.size() - 1;  // s: start index, e: end index
    int mid = 0;
    
    while (s <= e) {
        // Avoids integer overflow compared to (s + e) / 2
        mid = s + (e - s) / 2;

        // If target is greater, ignore left half
        if (a[mid] < t)
            s = mid + 1;

        // If target is smaller, ignore right half
        else if (a[mid] > t)
            e = mid - 1;

        // If element is found
        else
            return mid;
    }
    // Element not found
    return -1;
}

// Recursive implementation of binary search
int binaryrec(vector<int> a, int t, int s, int e) {
    // Base case: if the range is invalid
    if (s > e)
        return -1;

    int mid = s + (e - s) / 2;

    // If target is greater, search in the right half
    if (a[mid] < t)
        return binaryrec(a, t, mid + 1, e);

    // If target is smaller, search in the left half
    else if (a[mid] > t)
        return binaryrec(a, t, s, mid - 1);

    // If element is found
    else
        return mid;
}

int main() {
    // First test array and target
    vector<int> a1 = {-1, 0, 3, 4, 5, 9, 12};
    int t1 = 12;

    // Second test array and target
    vector<int> a2 = {-1, 0, 3, 5, 9, 12};
    int t2 = 12;

    cout << "\n\t\t\t Iterative Approach" << endl;
    cout << "Result of binary search (a1): " << binaryitrea(a1, t1) << endl;
    cout << "Result of binary search (a2): " << binaryitrea(a2, t2) << endl;

    cout << "\n\t\t\t Recursive Approach" << endl;

    // Performing recursive binary search on both arrays
    int s = 0, e = a1.size() - 1;
    cout << "Result of binary search (a1): " << binaryrec(a1, t1, s, e) << endl;

    s = 0, e = a2.size() - 1;
    cout << "Result of binary search (a2): " << binaryrec(a2, t2, s, e) << endl;

    return 0;
}

