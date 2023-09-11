/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        /* Approach:
            1. Sort + Linear Scan -- T.C: O(N log N), S.C: O(N)
            2. Sort + Linear Scan (Without extra space) -- T.C: O(N log N), S.C: O(1)
        */

        // Approach 2
        int n = groupSizes.size();

        for (int i = 0; i < n; i++) {
            groupSizes[i] = (groupSizes[i] << 9) | i;
        }

        // Sort
        sort(groupSizes.begin(), groupSizes.end());

        vector<vector<int>> ans = {{groupSizes[0] & 0x1FF}};

        int gSz = 0, curr = 0, ind = 0;
        for (int i = 1; i < n; i++) {
            gSz = (groupSizes[i - 1] >> 9);
            curr = (groupSizes[i] & 0x1FF);
            if (ans[ind].size() == gSz) {
                ind++;
                ans.push_back({curr});
            } else
                ans[ind].push_back(curr);
            // gSz = ((groupSizes[i] >> 9) & 0x1F4);
        }

        return ans;

        /* Approach 1
        int n = groupSizes.size();
        vector<pair<int, int>> group(n);

        for (int i = 0; i < n; i++) {           // T.C: O(N)
            group[i] = {groupSizes[i], i};
        }

        // Sort
        sort(group.begin(), group.end());

        vector<vector<int>> ans = {{group[0].second}};

        for (int i = 1; i < n; i++) {           // T.C: O(N)
            if (ans.back().size() == group[i - 1].first)
                ans.push_back({group[i].second});
            else
                ans.back().push_back(group[i].second);
        }

        return ans;
        */
    }
};
// @lc code=end
