/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        /* Approach:
            1. Sliding Window -- T.C: O(n), S.C: O(1)
        */

        int ans = 0;
        int l = 0, r = 0;
        int n = fruits.size();

        unordered_map<int, int> treeMap;

        while (r < n)
        {
            // Increment count for this tree type
            treeMap[fruits[r]]++;

            // We have overshoot the contraints
            if (treeMap.size() > 2)
            {
                treeMap[fruits[l]]--;
                if (treeMap[fruits[l]] == 0)
                    treeMap.erase(fruits[l]);
                l++;
            }

            if (treeMap.size() <= 2)
            {
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};
// @lc code=end
