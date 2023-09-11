/*
 * @lc app=leetcode id=1694 lang=cpp
 *
 * [1694] Reformat Phone Number
 */

// @lc code=start
class Solution {
   public:
    string reformatNumber(string number) {
        /* Approach:
            1. Simulation -- T.C: O(n), S.C: O(n)
        */

        // Approach 1 -- Simulation
        string digits;
        for (char c : number) {
            if (isdigit(c)) digits += c;
        }

        string ans;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            if (n - i == 4) {
                ans += digits.substr(i, 2);
                ans += '-';
                i++;
                continue;
            }
            if (n - i > 3) {
                ans += digits.substr(i, 3);
                ans += '-';
                i += 2;
                continue;
            }
            ans += digits[i];
        }

        return ans;
    }
};
// @lc code=end
