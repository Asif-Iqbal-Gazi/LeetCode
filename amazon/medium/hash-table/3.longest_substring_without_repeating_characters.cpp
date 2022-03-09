/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        /*
        Approach: Hash Table
        1. While looping through each char in the string, check if the char is already present is hashtable
        2. If not present just increase the current count and insert the char in hash table.
        3. However, if present then set current count to zero and remove the element from hash table.
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_set<char> set;
        int i = 0, res = 0, curr_len = 0, n = s.size();

        while (i < n)
        {
            if (set.find(s[i]) != set.end())
            {
                curr_len = 1;
                set.erase(s[i]);
            }
            else
            {
                set.insert(s[i]);
                curr_len++;
                res = max(curr_len, res);
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
