/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    string minWindow(string s, string t)
    {
        /* Approach:
            1. Sliding Window -- T.C: O(M + N), S.C: O(N)
            2. Sliding Window Optimised -- T.C: O(M + N), S.C: O(M + N)
        */

        // Approach 2
        int m = s.size();
        int n = t.size();
        // Edge case
        if (n > m)
            return "";

        // Char Map -- ASCII (0-128)
        vector<int> charMap(128, 0);

        // Build the char map
        for (char c : t)
            charMap[c]++;

        int left = 0;
        int right = 0;
        int counter = n;
        int minStart = 0;
        int minSize = INT_MAX;

        while (right < m)
        {
            if (charMap[s[right]] > 0)
                counter--;
            charMap[s[right]]--;
            right++;

            while (counter == 0)
            {
                if (minSize > right - left)
                {
                    minSize = right - left;
                    minStart = left;
                }
                charMap[s[left]]++;
                if (charMap[s[left]] > 0)
                    counter++;
                left++;
            }
        }
        return minSize == INT_MAX ? "" : s.substr(minStart, minSize);

        /* Approach 1
        int m = s.size();
        int n = t.size();

        // Edge Case
        if (n > m)
            return "";

        // Two Maps
        unordered_map<char, int> t_Map; // For Char Mapping String t
        unordered_map<char, int> s_Map; // For Char Mapping String s

        // Building t_Map
        for (auto c : t)
            t_Map[c]++;

        // Varible required for window size comparison
        int have = 0;
        int need = t.size();
        int l = 0; // Left index of window

        int minWindowlen = INT_MAX;    // Varible keeps track of minimum window length
        int leftIndexOfSubstring = -1; // Varible to keep track of left index of minimum window

        // Right index of window starts from zero
        for (int r = 0; r < m; r++)
        {
            auto it1 = t_Map.find(s[r]);
            if (it1 != t_Map.end())
            {
                // Char present in t_Map
                s_Map[s[r]]++; // Freq of char in s_Map incremented
                if (it1->second >= s_Map[s[r]])
                    have++; // Increment have only upto the freq in t_Map
            }

            while (have == need)
            {
                // We have found a window, let's minimize it
                // First let's update minWindowLen & leftIndexOfSubstring
                if (minWindowlen > r - l + 1)
                {
                    minWindowlen = r - l + 1;
                    leftIndexOfSubstring = l;
                }
                // Pop out leftmost element from window
                auto it2 = t_Map.find(s[l]);
                if (it2 != t_Map.end())
                {
                    // The char we are removing present in s_Map (As s_Map can contain only item present in t_Map)
                    s_Map[s[l]]--;
                    if (s_Map[s[l]] < it2->second)
                        have--; // Update have only when freq is less than taht of t_Map
                }
                l++;
            }
        }

        return minWindowlen == INT_MAX ? "" : s.substr(leftIndexOfSubstring, minWindowlen);
        */
    }
};
// @lc code=end
