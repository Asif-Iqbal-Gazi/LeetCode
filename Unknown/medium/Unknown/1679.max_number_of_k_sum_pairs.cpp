/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        /* Approach:
            1. Sort + Two Pointers -- T.C: O(n * log n), S.C: O(1)
            2. Using Map -- T.C: O(n), S.C: O(n)
        */

        // Approach 2
        int ans = 0;
        unordered_map<int, int> map;

        for (int x : nums)
        {
            if (map.find(k - x) == map.end())
                map[x]++;
            else
            {
                ans++;
                if (--map[k - x] == 0)
                    map.erase(k - x);
            }
        }
        return ans;

        /* Approach 1
        sort(nums.begin(), nums.end());         // O(n log n)

        int l = 0;
        int ans = 0;
        int sum = 0;
        int r = nums.size() - 1;

        while(l < r) {
            sum = nums[l] + nums[r];
            if(sum == k) {
                ans++;
                l++;
                r--;
            }
            else if(sum > k)
                r--;
            else
                l++;
        }

        return ans;
        */
    }
};
// @lc code=end
