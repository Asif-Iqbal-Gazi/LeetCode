/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        /*
        Approach 1: Sort and Compare
        1. First sort the array.
        2. Traverse the array from 2nd element and check if it is 1 greater than previous element.
        3. If yes increment the curr_len, if equal continue, if not the reset curr_len to 1, ans = max(curr_len, ans)

        Approach 2: Using Set
        1. First insert all elements of nums in an unordered set.
        2. Traverse through the set now, for each element check if the previous element exists.
        3. If the previous element does exist, then this can be a start of a sequence.
        4. So, start a while loop as long as next element is present in the set, incrementing curr_len.
        5. At the end of the loop set ans = max(ans, curr_len)
        */

        /* Approach 1
        if (nums.size() == 0)
            return 0;
        int ans = 0, curr_len = 1, n = nums.size();
        // Sort the array.
        sort(nums.begin(), nums.end());
        // Checking
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1] + 1)
                curr_len++;
            else if (nums[i] == nums[i - 1])
                continue;
            else
            {
                ans = max(curr_len, ans);
                curr_len = 1;
            }
        }
        // If the array is already sorted, the else part will never get executed. So, ans will always be '0'
        ans = max(curr_len, ans);
        return ans;
        */

        // Approach 2
        int ans = 0, n = nums.size();
        unordered_set<int> set(nums.begin(), nums.end());

        for (auto x : set)
        {
            if (set.find(x - 1) == set.end())
            {
                int curr_len = 1;
                while (set.find(x + 1) != set.end())
                {
                    curr_len++;
                    x++;
                }
                ans = max(curr_len, ans);
            }
        }
        return ans;
    }
};
// @lc code=end
