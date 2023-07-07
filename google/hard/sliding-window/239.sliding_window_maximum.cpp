/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
// Reached correct window size
// Reached correct window size
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        /* Approach:
            1. Sliding window -- T.C: O(n), S.C: O(k)
        */

        int l = 0, r = 0;
        int n = nums.size();
        deque<int> maxList;
        vector<int> ans(n - k + 1);

        while (r < n)
        {
            while (!maxList.empty() && maxList.back() < nums[r])
                maxList.pop_back();
            maxList.push_back(nums[r]);

            // Exceeded correct window size
            if (r - l + 1 > k)
            {
                if (maxList.front() == nums[l])
                    maxList.pop_front();
                l++;
            }

            // Reached correct window size
            if (r - l + 1 == k)
            {
                ans[l] = maxList.front();
            }
            r++;
        }

        return ans;
    }
};
// @lc code=end
