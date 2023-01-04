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
        /* Approach:
            1. Bruteforce -- T.C: O(N^2), S.C: O(N)
            2. Sliding Window + Unordered_set -- T.C: O(N), S.C: O(N)
            3. sliding Window + Unordered_map -- T.C: O(N), S.C: O(N) -- Optimal Solution as it will ensure single pass
        */

        // Approach 3
        int ans = 0;
        int n = s.size();
        int l = 0, r = 0;
        unordered_map<char, int> map;

        while (r < n)
        {
            if (map.find(s[r]) != map.end())
                l = max(map[s[r]] + 1, l);
            map[s[r]] = r;
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;

        /* Approach 2
        int ans = 0;
        int n = s.size();
        int l = 0, r = 0;
        unordered_set<char> set;

        while (r < n)
        {
            if (set.find(s[r]) == set.end())
            {
                ans = max(ans, r - l + 1);
                set.insert(s[r]);
                r++;
            }
            else
            {
                set.erase(s[l]);
                l++;
            }
        }
        return ans;
        */

        /* Approach 1
        int ans = 0;
        int n = s.size();
        unordered_set<char> set;

        for (int i = 0; i < n; i++)
        {
            set.clear();
            for (int j = i; j < n; j++)
            {
                if (set.find(s[j]) == set.end())
                {
                    ans = max(ans, j - i + 1);
                    set.insert(s[j]);
                }
                else
                    break;
            }
        }
        return ans;
        */
    }
};
// @lc code=end
