/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        /* Approach:
            1. Using Map -- T.C: O(n), S.C: O(1)
        */

        int freqMap[5] = {0};
        int ballonMap[5] = {1, 1, 2, 1, 2};

        for (char c : text) // O(n)
        {
            if (c == 'a')
                freqMap[0]++;
            else if (c == 'b')
                freqMap[1]++;
            else if (c == 'l')
                freqMap[2]++;
            else if (c == 'n')
                freqMap[3]++;
            else if (c == 'o')
                freqMap[4]++;
        }

        int ans = 1e5;
        for (int i = 0; i < 5; i++) // O(1)
            ans = min(ans, freqMap[i] / ballonMap[i]);

        return ans;
    }
};
// @lc code=end
