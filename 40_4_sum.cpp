/*
LeetCode Problem: 18. 4Sum


Approach:
1. Sort the input array to use the two-pointer technique effectively.
2. Use four pointers:
   - Two fixed pointers (`i` and `j`)
   - Two moving pointers (`s` and `e`) to find the remaining two numbers
3. Skip duplicates for all four positions to avoid repeated quadruplets.
4. Use `long long` to prevent integer overflow while summing.

Time Complexity: O(n^3)
   - Three nested loops: i, j, and two-pointer scan (s, e)
   - Skipping duplicates takes constant time
Space Complexity: O(1) (ignoring output space)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Step 1: Sort array
        int n = nums.size();
        int a, b, c, d;

        // Outer loop for the first number
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
            a = nums[i];

            // Second loop for the second number
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates
                b = nums[j];
                int s = j + 1, e = n - 1;

                // Two-pointer search for remaining two numbers
                while (s < e) {
                    c = nums[s];
                    d = nums[e];

                    // Use long long to avoid overflow
                    long long sum = (long long)a + b + c + d;// long long sum=1LL*(a+b+c+d);

                    if (sum > target) {
                        e--; // Sum too large, decrease end pointer
                    } else if (sum < target) {
                        s++; // Sum too small, increase start pointer
                    } else {
                        ans.push_back({a, b, c, d}); // Found a quadruplet
                        s++; e--;

                        // Skip duplicates for third and fourth numbers
                        while (s < e && nums[s] == nums[s - 1]) s++;
                        while (s < e && nums[e] == nums[e + 1]) e--;
                    }
                }
            }
        }

        return ans;
    }
};

// Sample main function to test the fourSum method
int main() {
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = sol.fourSum(nums, target);

    cout << "Quadruplets that sum to " << target << ":\n";
    for (auto quad : result) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i] << (i < quad.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }

    return 0;
}
