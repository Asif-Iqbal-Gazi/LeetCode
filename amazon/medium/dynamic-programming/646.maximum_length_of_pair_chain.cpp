/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
class Solution {
   public:
    int findLongestChain(vector<vector<int>> &pairs) {
        /* Approach:
            1. DP (Bottom Up) -- T.C: O(n^2), S.C: O(n)
            2. Greedy -- T.C: O(nlogn), S.C: O(1)
            3. Same as above, but beautiful code (From leetcode solution) -- T.C: O(nlogn), S.C: O(n)
        */

        // Approach 3 -- Greedy (Beautiful Code)
        int n = pairs.size();
        int intPairs[n];

        for (int i = 0; i < n; i++) {
            // Packing the pairs into a single integer
            intPairs[i] = ((pairs[i][1] + 1000) << 12) + pairs[i][0] + 1000;
        }
        // Sort the intPairs
        sort(intPairs, intPairs + n);

        int ans = 0;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if ((intPairs[i] & 0xFFF) > prev) {
                ans++;
                prev = intPairs[i] >> 12;
            }
        }
        return ans;

        /* Approach 2 -- Greedy
        //  Why Greedy works here ?
        //     Since are sort the pairs based on 'right' value, we can be sure that
        //     the pair with the smallest 'right' value will come first in the sorted array.

        //     Now say, we have PairA and PairB, where PairA comes before PairB in the sorted array.
        //     If PairA[1] < PairB[0], then we can be sure that PairA will be included in the answer.
        //     However, if PairA[1] >= PairB[0], then we need to be careful. We can pick PairA or PairB,
        //     But, since the array is sorted, we can be sure that PairB[1] >= PairA[1].
        //     Thus, PairA will be a better choice, becuase it will leave more space for other pairs to be included in the answer.

        //     So, in either case choosing PairA will be a better choice.
        //     This is why Greedy works here.

        int n = pairs.size();
        // Sort on the basis on 'right'
        sort(pairs.begin(), pairs.end(), [](const auto &p1, const auto &p2) -> bool {
            return p1[1] < p2[1];
        });

        int ans = 1;
        int prev = pairs[0][1];
        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > prev) {
                ans++;
                prev = pairs[i][1];
            }
        }
        return ans;
        */

        /* Approach 1 -- DP (Bottom Up)
        int n = pairs.size();
        // Sort on the basis on 'left'
        sort(pairs.begin(), pairs.end(), [](const auto &p1, const auto &p2) -> bool {
            return p1[0] < p2[0];
        });

        int dp[n];
        // Base Case
        dp[0] = 1;

        int ans = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            int maxPrev = 0;
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0])
                    maxPrev = max(dp[j], maxPrev);
            }
            dp[i] += maxPrev;
            ans = max(ans, dp[i]);
        }

        return ans;
        */
    }
};
// @lc code=end
