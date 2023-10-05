/*
 * @lc app=leetcode id=2038 lang=cpp
 *
 * [2038] Remove Colored Pieces if Both Neighbors are the Same Color
 */

// @lc code=start
class Solution {
   public:
    bool winnerOfGame(string colors) {
        /* Approach:
            1. Linear Scan -- T.C: O(N), S.C: O(1)
        */

        // Approach 1
        int count[2] = {0};
        int currCount[2] = {0};

        for (char c : colors) {
            currCount[c - 'A']++;
            if (currCount[c - 'A'] > 2)
                count[c - 'A']++;
            currCount[!(bool)(c - 'A')] = 0;
        }

        return count[0] > count[1];
    }
};
// @lc code=end
