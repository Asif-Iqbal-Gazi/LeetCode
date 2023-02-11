/*
 * @lc app=leetcode id=2009 lang=cpp
 *
 * [2009] Minimum Number of Operations to Make Array Continuous
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        /* Approach:
            1. Sort + Sliding Window -- T.C: O(nlogn), S.C: O(n)
            2. Sort + Binary Search -- T.C: O(nlogn), S.C: O(n)
            3. Sort + Binary Search -- T.C: O(nlogn), S.C: O(n)
        */

        // Approach 3 -- STL magic
        int n = nums.size();

        // Sort the nums array
        sort(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), unique(nums.begin(), nums.end())));

        int ans = n;
        int m = nums.size();
        // Sliding window with bianry searc
        for (int i = 0, j = 0; i < m; i++)
        {
            int upper_index = upper_bound(nums.begin(), nums.end(), (nums[i] + n - 1)) - nums.begin();
            ans = min(ans, n - upper_index + i);
        }
        return ans;

        /* Approach 2
        int n = nums.size();

        vector<int> unique;
        unordered_set<int> seen;

        // Build the unique array with help of set
        for (auto x : nums)
        {
            if (!seen.count(x))
                unique.push_back(x);
            seen.insert(x);
        }

        int ans = n;
        int m = unique.size();
        // Sort unique
        sort(unique.begin(), unique.end());

        for (int i = 0; i < m; i++)
        {
            int curr_end = unique[i] + n - 1;
            vector<int>::iterator upper = upper_bound(unique.begin(), unique.end(), curr_end);
            int len = upper - unique.begin() - i;
            ans = min(ans, n - len);
        }

        return ans;
        */

        /* Approach 1
        int n = nums.size();
        // Edge Case
        if (n == 1)
            return 0;
        vector<int> unique;
        // We will require a set to remove the duplicates
        set<int> s(nums.begin(), nums.end()); // T.C: O(nlogn)

        for (auto x : s) // T.C: O(n)
            unique.push_back(x);

        int m = unique.size();

        // Sliding window
        int ans = n;
        int l = 0, r = 0;
        while (l < m)
        {
            while (r < m && unique[r] < unique[l] + n)
                r++;
            ans = min(ans, n - r + l);
            if (ans == 1)
                return ans;
            l++;
        }
        return ans;
        */
    }
};
// @lc code=end
