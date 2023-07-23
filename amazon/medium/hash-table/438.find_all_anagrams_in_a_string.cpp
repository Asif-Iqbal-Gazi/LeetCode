/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        /* Approach:
            1. Sliding Window -- T.C: O(n), S.C: O(1)
        */

        // Approach 1
        // Edge Case
        if (s.size() < p.size())
            return {};

        int unqiueCount = 0;
        int freqMap[26] = {0};
        // Build freqMap for 'p'
        for (char c : p)
        {
            if (freqMap[c - 'a'] == 0)
                unqiueCount++;
            freqMap[c - 'a']++;
        }

        int l = 0;
        int r = 0;
        int n = s.size();
        vector<int> ans;

        while (r < n)
        {
            if (--freqMap[s[r] - 'a'] == 0)
                unqiueCount--;
            r++;

            // Maintain a valid window length
            while (r - l >= p.size())
            {
                // We have window of valid size, which contains anagram of p
                if (unqiueCount == 0)
                    ans.push_back(l);
                // Now we need to slide our window to right
                if (++freqMap[s[l] - 'a'] == 1)
                    unqiueCount++;
                l++;
            }
        }
        return ans;
    }
};
// @lc code=end
