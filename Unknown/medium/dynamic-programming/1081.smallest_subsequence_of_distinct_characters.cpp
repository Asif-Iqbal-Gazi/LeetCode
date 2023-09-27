/*
 * @lc app=leetcode id=1081 lang=cpp
 *
 * [1081] Smallest Subsequence of Distinct Characters
 */

// @lc code=start
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};
class Solution {
   private:
    string ans;
    int ansMask;
    int currPos;
    vector<char> unique;
    unordered_map<char, vector<int>> charPosMap;
    map<pair<int, int>, int> dp;

    int findIndex(int prevInd, int charInd) {
        char c = unique[charInd];
        if (prevInd == -1) return charPosMap[c][0];
        auto it = lower_bound(charPosMap[c].begin(), charPosMap[c].end(), prevInd);
        return it == charPosMap[c].end() ? -1 : *it;
    }

    bool solveTopDown(int prevInd, int currMask) {  // T.C: O(n * k * 2^26)
        // Base Cases
        if (currMask == ansMask)
            return true;

        if (dp.count({prevInd + 1, currMask}) > 0)
            return dp[{prevInd + 1, currMask}];

        for (int i = 0; i < unique.size(); i++) {
            // Check if already considered
            if (currMask & (1 << (unique[i] - 'a'))) continue;
            int nextPrevInd = findIndex(prevInd, i);
            // Check if there is valid position
            if (nextPrevInd == -1 || nextPrevInd < prevInd) continue;
            ans[currPos++] = unique[i];
            if (solveTopDown(nextPrevInd, currMask | (1 << (unique[i] - 'a')))) {
                return dp[{prevInd + 1, currMask}] = true;
            }
            currPos--;
        }
        return dp[{prevInd + 1, currMask}] = false;
    }

   public:
    string smallestSubsequence(string s) {
        /* Approach:
             1. DP (Bit Masking) -- T.C: O(n * k * 2^26), T.C: O(n * k * 2^26) -- TLE
             2. Using Monotonic Stack -- T.C: O(n), S.C: O(n)
        */

        // Approach 2 -- Monotonic Stack
        int n = s.size();
        int charPosMap[26] = {-1};

        // Take note of the last occurence
        for (int i = 0; i < n; i++) {
            charPosMap[s[i] - 'a'] = i;
        }

        vector<char> st;
        int seenMap[26] = {0};

        for (int i = 0; i < n; i++) {
            // Already seen, ignore
            if (seenMap[s[i] - 'a']) continue;
            // Maintain monotonic stack
            // Check if stack top char is lexicographically smaller than current char
            // If not, check if the char at the stack top is occuring later in the string
            // If it has later occurence, pop it
            while (!st.empty() && st.back() > s[i] && charPosMap[st.back() - 'a'] > i) {
                seenMap[st.back() - 'a'] = 0;
                st.pop_back();
            }
            seenMap[s[i] - 'a'] = 1;
            st.push_back(s[i]);
        }

        // Get stack size
        n = st.size();
        string ans(n, '0');

        for (int i = 0; i < n; i++)
            ans[i] = st[i];

        return ans;

        /* Approach 1 -- DP (Bit Masking)
        // Set global vars
        ansMask = 0;
        currPos = 0;
        unique.clear();
        charPosMap.clear();
        int n = s.size();

        for (int i = 0; i < n; i++) {        // T.C: O(n)
            charPosMap[s[i]].push_back(i);
            if (charPosMap[s[i]].size() == 1) {
                 unique.push_back(s[i]);
                 ansMask |=  1 << (s[i] - 'a');
            }
        }

        ans.resize(unique.size(), '0');
        sort(unique.begin(), unique.end());  // T.C: O(26 * log 26)

        solveTopDown(-1, 0);
        return ans;
        */
    }
};
// @lc code=end
