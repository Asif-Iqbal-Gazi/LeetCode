/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        /* Approach:
            1. Using Map -- T.C: O(N), S.C: O(N)
            2. Using Moore's Voting Algorithm -- T.C: O(N), S.C: O(1)
        */

        // Approach 2
        int n = nums.size();
        int countOne = 0, countTwo = 0;
        int candidateOne = 0, candidateTwo = 0;

        for (int x : nums) {
            if (x == candidateOne)
                countOne++;
            else if (x == candidateTwo)
                countTwo++;
            else if (countOne == 0) {
                countOne++;
                candidateOne = x;
            } else if (countTwo == 0) {
                countTwo++;
                candidateTwo = x;
            } else {
                countOne--;
                countTwo--;
            }
        }
        // Note: countOne and countTwo does not give actual frequencies of
        // candidateOne & candidateTwo
        countOne = countTwo = 0;
        for (int x : nums) {
            if (x == candidateOne)
                countOne++;
            else if (x == candidateTwo)
                countTwo++;
        }

        vector<int> result;
        if (countOne > n / 3) result.push_back(candidateOne);
        if (countTwo > n / 3) result.push_back(candidateTwo);
        return result;

        /* Approach 1
        int n = nums.size();
        int maxFreq = n / 3;
        vector<int> result;
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
            if (freq[x] > maxFreq) {
                result.push_back(x);
                freq[x] = INT_MIN;  // To avoid repeatation
            }
        }
        return result;
        */
    }
};
// @lc code=end
