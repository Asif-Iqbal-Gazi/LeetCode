/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution
{
private:
    /* Approach 1
    string ans;
    int ans_mask;
    vector<char> uniqueChars;
    unordered_map<char, vector<int>> positionMap;


    int findIndex(int prev_index, int char_index) {
        char c = uniqueChars[char_index];
        if(prev_index == -1)
            return positionMap[c][0];
        auto it = lower_bound(positionMap[c].begin(), positionMap[c].end(), prev_index);
        return it == positionMap[c].end() ? -1 : *it;
    }

    bool solveTopDown(int prev_index, int curr_mask, vector<vector<int>> &dp) {
        if(curr_mask == ans_mask)
            return dp[prev_index + 1][curr_mask] = true;

        if(dp[prev_index + 1][curr_mask] != -1) {
            return dp[prev_index + 1][curr_mask];
        }

        for(int i = 0; i < uniqueChars.size(); i++) {
            // Char taken, skip
            if(curr_mask & (1 << i)) continue;
            // For this char find it's valid index
            int next_prev = findIndex(prev_index, i);
            if(next_prev == -1 || next_prev < prev_index) continue;
            ans += uniqueChars[i];
            if(solveTopDown(next_prev, curr_mask | 1 << i, dp)) {
                return dp[prev_index + 1][curr_mask] = true;
            }
            ans.pop_back();
        }
        return dp[prev_index + 1][curr_mask] = false;
    }
    */

public:
    string removeDuplicateLetters(string s)
    {
        /* Approach:
            1. DP (Top Down) -- T.C: O(N*K), S.C: O(N*K) -- TLE
            2. Stack Based Solution -- T.C: O(n), S.C: O(n)
        */

        // Approach 2
        int n = s.size();
        int charMap[26] = {0};
        // Build charMap
        for (int i = 0; i < n; i++)
        { // O(n)
            charMap[s[i] - 'a'] = i;
        }

        vector<char> st;
        unordered_set<char> seen;

        for (int i = 0; i < n; i++)
        {
            // Already considered
            if (seen.find(s[i]) != seen.end())
                continue;
            // Stack is not monotonically increasing
            // Check if we can remove the stack top, we can do so,
            // if there is another occurence of stack top after i
            while (!st.empty() && st.back() > s[i] && charMap[st.back() - 'a'] > i)
            {
                seen.erase(st.back());
                st.pop_back();
            }
            st.emplace_back(s[i]);
            seen.insert(s[i]);
        }

        string ans;
        for (char c : st)
            ans += c;

        return ans;

        /* Approach 1
        ans = "";
        ans_mask = 0;

        int n = s.size();

        // Build positionMap, unique list & ans_mask
        for(int i = 0; i < n; i++) {
            positionMap[s[i]].push_back(i);
            if(positionMap[s[i]].size() == 1) {
                uniqueChars.push_back(s[i]);
                ans_mask |= 1 << (s[i] - 'a');
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>((1 << uniqueChars.size()), -1));

        // Sort unique in lexicographical order
        sort(uniqueChars.begin(), uniqueChars.end());
        cout << "Size: " << n << "\n";
        cout << "Unique: " << uniqueChars.size() << "\n";
        cout << solveTopDown(-1, 0, dp) << " Bool\n";

        return ans;
        */
    }
};
// @lc code=end
