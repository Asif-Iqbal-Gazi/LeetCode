/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution
{
public:
    /* Approach 1
    bool checkDict(int l, int r, const string &s, unordered_set<string> &wordDict){
        string checkMe = s.substr(l, r - l + 1);
        //cout << " " << checkMe << " ";
        return (wordDict.find(checkMe) != wordDict.end());
    }

    bool solveTopDown(int i, const string &s, unordered_set<string> &wordDict, vector<int> &dp){
        if(i == s.size())
            return true;

        if(dp[i] != -1)
            return dp[i];

        bool ans = false;
        for(int r = i; r < s.size(); r++){
            if(checkDict(i, r, s, wordDict)){
                ans |= solveTopDown(r + 1, s, wordDict, dp);
            }
        }
        return dp[i] = ans;
    }
    */

    /* Approach 1
    bool solveRec(int i, const string &s, unordered_set<string> &wordDict){
        if(i == s.size())
            return true;

        bool ans = false;
        for(int r = i; r < s.size(); r++){
            if(checkDict(i, r, s, wordDict)){
                ans |= solveRec(r + 1, s, wordDict);
            }
        }
        return ans;
    }
    */

    bool wordBreak(string s, vector<string> &wordDict)
    {
        /* Approach:
            1. Recursion -- T.C: O(n!)
            2. DP (Top Down) -- T.C: O(n^2), T.C: O(m)
            3. Dp (Bottom Up) -- T.C: O(n^2 * k), T.C: O(m)
        */

        /* Approach 3 -- DP (Bottom Up)
            DP State :
                dp[i] : Presence / Absence of substring(i, N) in dictionary
            DP Transition :
                dp[i] = 1, iff substring[i, k] is in dictionary and dp[k+1] = 1
                `       0, Otherwise
            Base Case :
                dp[N] = 1
            Final Problem :
                dp[0]
        */

        int n = s.size();
        int minWordLen = INT_MAX;
        unordered_set<string> dict;
        // Insert dictionary words into an unordered_set for quicker access
        for (string word : wordDict) // O(d), d: wordDict.size()
        {
            if (word.size() < minWordLen)
                minWordLen = word.size();
            dict.insert(word);
        }

        int dp[n + 1];
        // Base Case
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) // O(n^2 * k)
        {
            dp[i] = 0;
            for (int k = i; k < n; k++) // O(n * k)
            {
                if (k - i + 1 < minWordLen)
                    continue;
                string currSubStr = s.substr(i, k - i + 1); // O(k)
                if (dp[k + 1] && dict.find(currSubStr) != dict.end())
                {
                    dp[i] = 1;
                    break; // No need to proceed further
                }
            }
        }
        return dp[0];

        /* Approach 2
        vector<int> dp(s.size(), -1);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        return solveTopDown(0, s, wordSet, dp);
        */

        /* Approach 1
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        return solveRec(0, s, wordSet);
        */
    }
};
// @lc code=end
