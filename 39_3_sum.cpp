#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:

    // ❌ Brute Force Approach — Time Complexity: O(n^3 * log 3) = O(n^3) — (TLE)
    vector<vector<int>> threeSumBrute(vector<int>& nums) {
        cout << "\n[Brute Force Steps]\n";
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0) {
                        vector<int> trip = {nums[i], nums[j], nums[k]};
                        sort(trip.begin(), trip.end());
                        if(s.find(trip) == s.end()) {
                            cout << "Found triplet: [" << trip[0] << ", " << trip[1] << ", " << trip[2] << "]\n";
                            s.insert(trip);
                            ans.push_back(trip);
                        }
                    }
                }
            }
        }
        return ans;
    }

    // ✅ Hashing (Two-Sum inside for-loop) Approach — Time Complexity: O(n^2 * log 3) = O(n^2) — (TLE on large input)
    vector<vector<int>> threeSumHashing(vector<int>& nums){
        cout << "\n[Hashing Steps]\n";
        set<vector<int>> uniqueset;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int tar = -nums[i];
            set<int> toFindC;
            for(int j = i + 1; j < n; j++) {
                int c = tar - nums[j];
                if(toFindC.find(c) != toFindC.end()) {
                    vector<int> trip = {nums[i], nums[j], c};
                    sort(trip.begin(), trip.end());
                    if(uniqueset.find(trip) == uniqueset.end())
                        cout << "Found triplet: [" << trip[0] << ", " << trip[1] << ", " << trip[2] << "]\n";
                    uniqueset.insert(trip);
                }
                toFindC.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(uniqueset.begin(), uniqueset.end());
        return ans;
    }

    // ✅ Optimal Two-Pointer Approach (with Sorting) — Time Complexity: O(n^2+nlogn)
    vector<vector<int>> threeSumOptimal(vector<int>& nums){
        cout << "\n[Two Pointer Steps]\n";

        int n = nums.size();
        vector<vector<int>> ans;

        // Step 1: Sort the array to apply two-pointer technique
        sort(nums.begin(), nums.end());

        // Step 2: Fix one number and find two others using two pointers
        for(int i = 0; i < n; i++) {
            // Skip duplicates for the first number
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int s = i + 1;       // Left pointer
            int e = n - 1;       // Right pointer

            // Step 3: While left < right, check sum of nums[i] + nums[s] + nums[e]
            while(s < e){
                int sum = nums[i] + nums[s] + nums[e];

                if(sum < 0) {
                    // Too small: need larger value -> move left pointer right
                    s++;
                }
                else if(sum > 0) {
                    // Too large: need smaller value -> move right pointer left
                    e--;
                }
                else {
                    // Found valid triplet
                    cout << "Found triplet: [" << nums[i] << ", " << nums[s] << ", " << nums[e] << "]\n";
                    ans.push_back({nums[i], nums[s], nums[e]});
                    s++;
                    e--;

                    // Skip duplicates for second number
                    while(s < e && nums[s] == nums[s - 1]) s++;

                    // Skip duplicates for third number
                    while(s < e && nums[e] == nums[e + 1]) e--;
                }
            }
        }

        return ans;
    }
};

// ------------------- Main Function -------------------

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution sol;

    // Run Brute Force
    vector<vector<int>> resBrute = sol.threeSumBrute(nums);

    // Run Hashing
    vector<vector<int>> resHashing = sol.threeSumHashing(nums);

    // Run Two-pointer Optimal
    vector<vector<int>> resOptimal = sol.threeSumOptimal(nums);

    // Print Results
    cout << "\n\n[Final Triplets Comparison]\n";

    cout << "\nBrute Force Output:\n";
    for (auto &triplet : resBrute) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }

    cout << "\nHashing Output:\n";
    for (auto &triplet : resHashing) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }

    cout << "\nTwo Pointer Output:\n";
    for (auto &triplet : resOptimal) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }

    return 0;
}
