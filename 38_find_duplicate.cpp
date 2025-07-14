//   leet code   287. Find the Duplicate Number

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // ✅ Approach 1: Using unordered_set
    /*
    Time Complexity: O(n)
        - Single pass through nums array of size n
        - Average O(1) insertion and lookup in unordered_set
    Space Complexity: O(n)
        - Extra space to store up to n unique elements
    */
    int findDuplicateSet(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return nums[i];
            }
            s.insert(nums[i]);
        }  
        return -1;
    }

    // ✅ Approach 2: Using frequency array (vector)
    /*
    Time Complexity: O(n)
        - One pass to build frequency array → O(n)
        - One pass to find the duplicate → O(n)
        - Total = O(n)
    Space Complexity: O(n)
        - Extra space for frequency vector of size n
    */
    int findDuplicateFreq(vector<int>& nums) {
        vector<int> f(nums.size(), 0);
        for (int val : nums) f[val]++;
        for (int i = 0; i < f.size(); i++) {
            if (f[i] > 1) return i;
        }
        return -1;
    }

    // ✅ Approach 3: Floyd’s Tortoise and Hare (Cycle Detection)
    /*
    Time Complexity: O(n)
        - Phase 1: O(n) to find the intersection point
        - Phase 2: O(n) to find the cycle entrance (duplicate)
        - Total = O(n)
    Space Complexity: O(1)
        - No extra space used
    */
    int findDuplicateFloyd(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        // Phase 1: Detect cycle
        do {
            slow = nums[slow];          // +1 step
            fast = nums[nums[fast]];    // +2 steps
        } while (slow != fast);

        // Phase 2: Find entry point of cycle (duplicate)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

// ✅ Main function to demonstrate all 3 approaches
int main() {
    vector<int> nums = {1, 3, 4, 2, 2}; // Duplicate is 2

    Solution sol;

    cout << "//  Approach 1: Using unordered_set" << endl;
    cout << "Duplicate : " << sol.findDuplicateSet(nums) << "   (Time: O(n), Space: O(n))" << endl << endl;

    cout << "//  Approach 2: Using frequency array (vector)" << endl;
    cout << "Duplicate : " << sol.findDuplicateFreq(nums) << "   (Time: O(n), Space: O(n))" << endl << endl;

    cout << "//  Approach 3: Floyd's Tortoise and Hare (Cycle Detection)" << endl;
    cout << "Duplicate : " << sol.findDuplicateFloyd(nums) << "   (Time: O(n), Space: O(1))" << endl;
 
    return 0;
}
