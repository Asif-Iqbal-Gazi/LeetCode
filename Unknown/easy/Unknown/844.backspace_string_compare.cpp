/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        /*
            1. Linear Scan + Stack -- T.C: O(N), S.C: O(N)
            2. Linear Scan (Constant Space) -- T.C: O(N), S.C: O(1)
        */

        // Approach 2
        int delCount1 = 0;
        int delCount2 = 0;

        int i = s.size() - 1;
        int j = t.size() - 1;

        while (i >= 0 || j >= 0) {
            // Process 's'
            while (i >= 0) {
                if (s[i] == '#') {
                    i--;
                    delCount1++;  // Increment delCount1 (no of char we need to delete on left)
                } else if (delCount1 > 0) {
                    i--;
                    delCount1--;  // Decrement delCount1 (as we are not counting this char)
                } else
                    break;
            }
            // Process 't'
            while (j >= 0) {
                if (t[j] == '#') {
                    j--;
                    delCount2++;  // Increment delCount2 (no of char we need to delete on left)
                } else if (delCount2 > 0) {
                    j--;
                    delCount2--;  // Decrement delCount2 (as we are not counting this char)
                } else
                    break;
            }
            // Check if two char are same
            if (i >= 0 && j >= 0 && s[i] != t[j])
                return false;
            // Check if we have already exhausted char in either of the string
            if ((i >= 0) != (j >= 0))
                return false;
            i--, j--;
        }
        return true;

        /* Approach 1 
        string s1;
        for (char c : s) {
            if (c != '#')
                s1 += c;
            else if (!s1.empty())
                s1.pop_back();
        }

        string s2;
        for (char c : t) {
            if (c != '#')
                s2 += c;
            else if (!s2.empty())
                s2.pop_back();
        }

        return s1 == s2;
        * /
    }
};
// @lc code=end
