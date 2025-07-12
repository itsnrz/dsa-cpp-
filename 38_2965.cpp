#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // ✅ Approach 1: Using unordered_set + sum difference
    /*
    Time Complexity: O(n^2)
        - Traverse the entire s x s grid once
    Space Complexity: O(n^2)
        - unordered_set can store up to s^2 unique elements
    */
    vector<int> findMissingAndRepeatedUsingSet(vector<vector<int>>& grid) {
        unordered_set<int> s;
        vector<int> ans;
        int size = grid.size();
        int repeated = -1, actualSum = 0;

        // Step 1: Find repeated and compute sum
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                actualSum += grid[i][j];
                if (s.find(grid[i][j]) != s.end()) {
                    repeated = grid[i][j];
                }
                s.insert(grid[i][j]);
            }
        }

        // Step 2: Calculate missing using sum formula
        int expectedSum = (size * size) * (size * size + 1) / 2;
        int missing = expectedSum + repeated - actualSum;
        ans.push_back(repeated);
        ans.push_back(missing);
        return ans;
    }

    // ✅ Approach 2: Using frequency array (vector)
    /*
    Time Complexity: O(n^2)
        - Traverse the grid and then the frequency array
    Space Complexity: O(n^2)
        - Extra space for frequency array of size s^2 + 1
    */
    vector<int> findMissingAndRepeatedUsingFreq(vector<vector<int>>& grid) {
        int s = grid.size();
        vector<int> f(s * s + 1, 0); // frequency for values 1 to s*s

        // Step 1: Count frequency of all numbers
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                f[grid[i][j]]++;
            }
        }

        // Step 2: Find repeated and missing
        int r = -1, m = -1;
        for (int i = 1; i <= s * s; i++) {
            if (f[i] == 2) r = i;
            if (f[i] == 0) m = i;
        }

        return {r, m};
    }
};

// ✅ Main function to demonstrate both approaches
int main() {
    vector<vector<int>> grid = {
        {1, 2},
        {2, 4}
    };

    Solution sol;

    cout << "//  Approach 1: Using unordered_set + sum difference" << endl;
    vector<int> res1 = sol.findMissingAndRepeatedUsingSet(grid);
    cout << "Result: Repeated = " << res1[0] << ", Missing = " << res1[1] << endl;
    cout << "Time: O(n^2), Space: O(n^2)" << endl << endl;

    cout << "//  Approach 2: Using frequency array" << endl;
    vector<int> res2 = sol.findMissingAndRepeatedUsingFreq(grid);
    cout << "Result: Repeated = " << res2[0] << ", Missing = " << res2[1] << endl;
    cout << "Time: O(n^2), Space: O(n^2)" << endl;

    return 0;
}
