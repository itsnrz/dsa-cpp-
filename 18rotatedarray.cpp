//    lc=33    search in rotated sorted array



/*🔍 Problem Summary:

You're given a sorted array that has been rotated at some pivot, and you have to find the index of a target element in O(log n) time.



Example:
Original Sorted:    [1, 2, 3, 4, 5, 6, 7]
Rotated Array:      [4, 5, 6, 7, 1, 2, 3]
Target = 2 → index = 5



🚀 Core Idea (Intuition):

At any point in the array during binary search:

    One half is always sorted.

    We can use that sorted half to eliminate the other half.



🔁 Step-by-Step Intuition:

1. Use standard binary search logic:
mid = (start + end) / 2;

2. Check if nums[mid] == target.
✅ If yes, return mid.

3. Determine which half is sorted:
    If nums[start] <= nums[mid], the left half is sorted.
    Else, the right half is sorted.

4. Now decide where to move:
📌 If left half is sorted:
    Check if target lies between start and mid:
        Yes → search in left half (end = mid - 1)
        No → search in right half (start = mid + 1)

📌 If right half is sorted:
    Check if target lies between mid and end:
        Yes → search in right half (start = mid + 1)
        No → search in left half (end = mid - 1)

Repeat this until you either:

    Find the target, or

    Exit the loop → return -1 (not found)

*/
#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int e=nums.size()-1,s=0,mid=-1;
    while(s<=e){
        mid=s+(e-s)/2;
        if(nums[mid]==target)return mid;
        if(nums[s]<=nums[mid]){  //left sorted
            if(nums[s]<=target&&nums[mid]>=target)e=mid-1;
            else s=mid+1;
        }
        else{// right sorted
            if(nums[mid]<=target&&nums[e]>=target)s=mid+1;
            else e=mid-1;
        }
    }        
    return -1;
}
int main() {
    // First test array and target
    vector<int> a1 = {4,5,6,7,0,1,2};
    int t1 =0;
    cout << "Result of binary search (a1): " <<search(a1, t1) << endl;
    return 0;
}


/*🌀 Step-by-step Execution:

Initial:
s = 0, e = 6
nums = [4, 5, 6, 7, 0, 1, 2]
target = 0


🔁 1st Iteration:
mid = s + (e - s) / 2 = 0 + (6 - 0) / 2 = 3
nums[mid] = nums[3] = 7

Check if nums[mid] == target? → 7 != 0 → keep going

Now check if left side is sorted:

nums[s] = 4, nums[mid] = 7 → 4 <= 7 → YES → left sorted

Now, is target in left half?

nums[s] <= target <= nums[mid] → 4 <= 0 <= 7 → ❌ false

So, discard left side:

s = mid + 1 = 4


🔁 2nd Iteration:
s = 4, e = 6
mid = 4 + (6 - 4) / 2 = 5
nums[mid] = 1

Check if nums[mid] == target? → 1 != 0 → continue

Check if left is sorted:

nums[s] = 0, nums[mid] = 1 → 0 <= 1 → YES → left sorted

Check if target is in left half:

0 <= 0 <= 1 → ✅ true

So, search in left half:

e = mid - 1 = 4


🔁 3rd Iteration:
s = 4, e = 4
mid = 4 + (4 - 4)/2 = 4
nums[mid] = 0

✅ nums[mid] == target → 0 == 0 → found!
✅ Output:

Result of binary search (a1): 4
Target 0 is found at index 4.



                          🔁 Recap of Steps:
                          
Iteration	    s	      e	        mid         nums[mid]	   Decision
1	            0	      6	        3	         7	           Left sorted, target in right
2	            4	      6	        5	         1	           Left sorted, target in left
3	            4	      4	        4	         0	           ✅ Found target*/