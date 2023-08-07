/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
   private:
    int N;
    string s;
    vector<string> ds;
    vector<vector<string>> res;
    bool dp[16][16] = {false};
    void findValidPartition(int sInd) {
        // Base Case
        if (sInd == N) {
            res.push_back(ds);
            return;
        }

        for (int eInd = sInd; eInd < N; eInd++) {
            if (s[sInd] == s[eInd] && (eInd - sInd <= 2 || dp[sInd + 1][eInd - 1])) {
                dp[sInd][eInd] = true;
                ds.push_back(s.substr(sInd, (eInd - sInd + 1)));
                findValidPartition(eInd + 1);
                ds.pop_back();  // Backtracking
            }
        }
    }
    /* Approach 1 -- Backtracking
    bool isPalindrome(int l, int r, string &s) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
    void findValidPartition(int sInd, string &s, vector<string> &ds, vector<vector<string>> &res) {
        // Base Case
        if (sInd == s.size()) {
            res.push_back(ds);
            return;
        }

        for (int eInd = sInd; eInd < s.size(); eInd++) {
            if (isPalindrome(sInd, eInd, s)) {
                ds.push_back(s.substr(sInd, (eInd - sInd + 1)));
                findValidPartition(eInd + 1, s, ds, res);
                ds.pop_back();  // Backtracking
            }
        }
    }
    */

   public:
    vector<vector<string>> partition(string s) {
        /* Approach:
            1. Backtracking -- T.C: O(n*2^n), S.C: O(k*x)
            2. DP + Backtracking -- T.C: O(n*2^n), S.C: O(k*x)
        */

        // Approach 2 -- DP + Backtracking
        N = s.size();
        this->s = s;
        ds.clear();
        res.clear();
        findValidPartition(0);
        return res;

        /* Approach 1 -- Backtracking
        int n = s.size();
        vector<string> ds;
        vector<vector<string>> res;
        findValidPartition(0, s, ds, res);
        return res;
        */
    }
};
// @lc code=end
