/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
 */

// @lc code=start
class Solution {
   public:
    string decodeAtIndex(string s, int k) {
        /* Approach:
            1. Linear Scan -- T.C: O(n), S.C: O(1)
                Observe, that if we perform decoding of the encoding string, then kth char will
                always be a char (alpha) from our original string
                    Find the length of the decoded string and work from back word
        */

        // Approach 1
        int n = s.size();
        long long size = 0;

        // Calculate the size of the decoded string
        for (char c : s) {
            if (isdigit(c))
                size *= c - '0';
            else
                size++;
        }

        // Start from backward updating both k and size
        for (int i = n - 1; i >= 0; i--) {
            k %= size;
            if (k == 0 && isalpha(s[i]))
                return (string) "" + s[i];
            if (isdigit(s[i]))
                size /= s[i] - '0';
            else
                size--;
        }

        return "";
    }
}
// @lc code=end
