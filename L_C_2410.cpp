#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
2410. Maximum Matching of Players With Trainers
------------------------------------------------
You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. 
You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.

The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's capacity.
Each player can be matched with at most one trainer, and each trainer with at most one player.

Return the maximum number of matchings.

Example 1:
Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2

Example 2:
Input: players = [1,1,1], trainers = [10]
Output: 1

Constraints:
1 <= players.length, trainers.length <= 1e5
1 <= players[i], trainers[j] <= 1e9
*/

class Solution {
public:
    // Approach 1: Nested loop (Amortized linear after sorting)
    /*
        Time Complexity:
            - Sorting players: O(n log n)
            - Sorting trainers: O(m log m)
            - Matching loop: O(n + m) amortized (each trainer is considered only once)
            => Total: O(n log n + m log m)

        Space Complexity:
            - O(1) extra space (excluding input vectors; sorting is in-place)
    */
    int matchUsingNestedLoop(vector<int> players, vector<int> trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int count = 0, indx = 0;
        for (int i = 0; i < players.size(); i++) {
            for (int j = indx; j < trainers.size(); j++) {
                if (players[i] <= trainers[j]) {
                    count++;
                    indx = j + 1;
                    break;
                }
            }
        }
        return count;
    }

    // Approach 2: Two-pointer greedy approach
    /*
        Time Complexity:
            - Sorting players: O(n log n)
            - Sorting trainers: O(m log m)
            - Two-pointer scan: O(n + m)
            => Total: O(n log n + m log m)

        Space Complexity:
            - O(1) extra space (excluding input vectors; sorting is in-place)
    */
    int matchUsingTwoPointers(vector<int> players, vector<int> trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int count = 0, i = 0, j = 0;
        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return count;
    }
};

// ---------- MAIN FUNCTION WITH SAMPLE INPUTS ----------
int main() {
    Solution sol;

    vector<int> players1 = {4, 7, 9};
    vector<int> trainers1 = {8, 2, 5, 8};

    vector<int> players2 = {1, 1, 1};
    vector<int> trainers2 = {10};

    cout << "=== Example 1 ===" << endl;
    cout << "Nested Loop Output: " << sol.matchUsingNestedLoop(players1, trainers1) << endl;
    cout << "Two Pointer Output: " << sol.matchUsingTwoPointers(players1, trainers1) << endl;

    cout << "\n=== Example 2 ===" << endl;
    cout << "Nested Loop Output: " << sol.matchUsingNestedLoop(players2, trainers2) << endl;
    cout << "Two Pointer Output: " << sol.matchUsingTwoPointers(players2, trainers2) << endl;

    return 0;
}
