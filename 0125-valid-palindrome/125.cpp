class Solution {
  public:
    bool isPalindrome(string s) {
        /*
         * Approach:
         * 1. Two Pointers -- T.C: O(N), S.C: O(1)
         *      - Use two pointers, skip non-alphanumeric, compare lowercase.
         * 2. String Filtering -- T.C: O(N), S.C: O(N)
         *      - Build filtered lowercase string and compare with reverse.
         */

        // Approach 1 -- Two Pointers
        int l = 0, r = s.size() - 1;

        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;

            if (tolower(s[l]) != tolower(s[r]))
                return false;

            l++;
            r--;
        }

        return true;

        /* Approach 2 -- String Filtering
        string t;
        for (char c : s) {
            if (isalnum(c))
                t += tolower(c);
        }

        int l = 0, r = t.size() - 1;
        while (l < r) {
            if (t[l++] != t[r--])
                return false;
        }

        return true;
        */
    }
};
