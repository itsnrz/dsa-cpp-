#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ✅ Brute Force Approach
    /*
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    */
    vector<int> twoSumBrute(vector<int>& nums, int target) {
        int s = nums.size();
        for (int i = 0; i < s; i++) {
            for (int j = i + 1; j < s; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    // ✅ Two Pointer Approach (after sorting)
    /*
    Time Complexity: O(n log n) — due to sorting
    Space Complexity: O(n) — storing value-index pairs
    */
    vector<int> twoSumTwoPointer(vector<int>& nums, int target) {
        vector<pair<int, int>> p;
        for (int i = 0; i < nums.size(); i++) {
            p.push_back({nums[i], i});
        }
        sort(p.begin(), p.end());

        int s = 0, e = nums.size() - 1;
        while (s < e) {
            int sum = p[s].first + p[e].first;
            if (sum == target) return {p[s].second, p[e].second};
            else if (sum < target) s++;
            else e--;
        }
        return {-1, -1};
    }

    // ✅ Hashing (Optimal)
    /*
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    vector<int> twoSumHashing(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int second = target - first;
            if (m.find(second) != m.end()) {
                return {i, m[second]};
            }
            m[first] = i;
        }
        return {-1, -1};
    }
};

// ✅ Main function to test all approaches
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;

    // ✅ Approach 1: Brute Force
    cout << "//  Approach 1: Brute Force" << endl;
    vector<int> res1 = sol.twoSumBrute(nums, target);
    cout << "Indices: [" << res1[0] << ", " << res1[1] << "]" << endl;
    cout << "Time Complexity: O(n^2), Space Complexity: O(1)\n" << endl;

    // ✅ Approach 2: Two Pointer (after sorting)
    cout << "//  Approach 2: Two Pointer (after sorting)" << endl;
    vector<int> res2 = sol.twoSumTwoPointer(nums, target);
    cout << "Indices: [" << res2[0] << ", " << res2[1] << "]" << endl;
    cout << "Time Complexity: O(n log n), Space Complexity: O(n)\n" << endl;

    // ✅ Approach 3: Hashing
    cout << "//  Approach 3: Hashing" << endl;
    vector<int> res3 = sol.twoSumHashing(nums, target);
    cout << "Indices: [" << res3[0] << ", " << res3[1] << "]" << endl;
    cout << "Time Complexity: O(n), Space Complexity: O(n)" << endl;

    return 0;
}
