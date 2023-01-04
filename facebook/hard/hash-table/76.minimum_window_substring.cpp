/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        /* Approch:
            1. Sliding Window + Hash table -- T.C: O(M + N), S.C: O(N)
        */

        int m = s.size();
        int n = t.size();

        // Edge case
        if (n > m)
            return "";

        // Two Maps
        unordered_map<char, int> t_Map; // For Char mapping string t
        unordered_map<char, int> s_Map; // For Char mapping string s

        // Building t_Map
        for (char c : t)
            t_Map[c]++;

        // Variable to compare charMap in window
        int have = 0;
        int need = n;
        int l = 0;

        // Varibale to keep track of window
        int minWindowSize = INT_MAX; // Keeps track of minimum window size
        int leftIndexOfWindow = -1;  // Keeps track of left index of minimum window

        // Right index of window starts from zero
        for (int r = 0; r < m; r++)
        {
            // Find the char at index 'r' in t_Map
            auto it1 = t_Map.find(s[r]);
            // If present
            if (it1 != t_Map.end())
            {
                // Increment the freq of s_Map(s[r])
                s_Map[s[r]]++;
                if (it1->second >= s_Map[s[r]])
                    have++; // Increment our have counter as we have the required no of s[r]
            }

            // Check if we have a valid window
            while (need == have)
            {
                // We have found a window, let's minimize it
                // First let's update minWindowLen & leftIndexOfSubstring
                if (minWindowSize > r - l + 1)
                {
                    minWindowSize = r - l + 1;
                    leftIndexOfWindow = l;
                }
                // Pop out leftmost element from the window
                auto it2 = t_Map.find(s[l]);
                if (it2 != t_Map.end())
                {
                    // This char is in our t_Map
                    // Reduce it's frequency from s_Map
                    s_Map[s[l]]--;
                    // Check if we have the required no of this char
                    if (it2->second > s_Map[s[l]])
                        have--;
                }
                l++; // Final reduce the window size;
            }
        }

        return minWindowSize == INT_MAX ? "" : s.substr(leftIndexOfWindow, minWindowSize);
    }
};
// @lc code=end
