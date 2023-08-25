/*
    2813. Maximum Elegance of a K-Length Subsequence
    https://leetcode.com/problems/problems/maximum-elegance-of-a-k-length-subsequence/description/
*/

class Solution {
   public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        /* Approach:
            1. Sort and be Greedy -- T.C: O(NlogN), S.C: O(N)
                -- Sort items based on profit
                -- Pick top k items greedily, as the profit is non-decreasing, it gurarantees the maximum profit collected so far.
                -- Now, for the k items, we need to find the maximum elegance.
                -- We will use a seen set to keep track of the categories seen so far.
                -- We will also, store the corresponding pofit for each duplicate category.
                -- Once we have picked k items, we will check rest n - k items and select an items for which we have not seen the category before.
                   To do this, we will pop duplicate items from the back of our duplicate category vector and add the contribution of the item we have not seen before.
        */

        int n = items.size();
        // Sort items based on profit
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });

        // Pick top k items greedily, as the profit is non-decreasing, it gurarantees the maximum profit collected so far.
        long long currProfit = 0, ans = 0, uniqueCategories = 0;
        unordered_set<int> seen;
        vector<int> duplicateProfit;

        for (int i = 0; i < n; i++) {
            if (i < k) {
                if (seen.count(items[i][1]))
                    duplicateProfit.push_back(items[i][0]);
                currProfit += items[i][0];
            } else if (!seen.count(items[i][1])) {
                if (duplicateProfit.empty()) break;  // We have already seen k unique categories
                currProfit += items[i][0] - duplicateProfit.back();
                duplicateProfit.pop_back();
            }
            seen.insert(items[i][1]);
            uniqueCategories = seen.size() * seen.size();
            ans = max(ans, currProfit + uniqueCategories);
        }
        return ans;
    }
};