/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        /* Approach:
            1. DP (Bottom Up) -- T.C: O(n), S.C: O(n)
            2. DP (Bottom Up + Space Optimised) -- T.C: O(n), S.C: O(1)
            3. Greedy (Two Pointers) -- T.C: O(n), S.C: O(1)
        */

        // Approach 3
        int ans = 0;
        int sum = 0;
        int maxTime = 0;

        int l = 0;
        int r = 1;
        int n = colors.size();

        while (r < n)
        {
            sum = neededTime[l];
            maxTime = neededTime[l];
            while (r < n && colors[r] == colors[r - 1])
            {
                sum += neededTime[r];
                maxTime = max(maxTime, neededTime[r]);
                r++;
            }
            ans += sum - maxTime;
            l = r;
            r = l + 1;
        }

        return ans;

        /*
        DP State:
            dp[i] : Minimum time of removing balloons s.t prefix[0: i] is valid
        DP Transition:
            int lastPicked = 0;
            dp[i] : if(colors[i] != colors[i - 1])
                        dp[i - 1]
                        lastPicked = i;
                    else
                        dp[i - 1] + min(cost[prevIndex], neededTime[i]);
                        if(neededTime[lastPicked] < neededTime[i])
                            lastPicked = i;

        DP Base Case:
            lastPicked = 0'
            dp[0] = 0
            dp[1] = 0

        Answer:
            d[n - 1]
        */

        /* Approach 2
        // Base Case
        int prev = 0;
        int curr = 0;
        int lastPicked = 0;
        int n = colors.size();

        for(int i = 1; i < n; i++) {
            curr = prev;
            if(colors[i] != colors[i - 1])
                lastPicked = i;
            else {
                curr += min(neededTime[lastPicked], neededTime[i]);
                if(neededTime[lastPicked] < neededTime[i])
                    lastPicked = i;
            }
            prev = curr;
        }

        return prev;
        */

        /* Approach 1
        int n = colors.size();

        int dp[n];
        // Base Case
        dp[0] = 0;
        int lastPicked = 0;

        for(int i = 1; i < n; i++) {
            if(colors[i] != colors[i - 1]) {
                dp[i] = dp[i - 1];
                lastPicked = i;
            }
            else {
                dp[i] = dp[i - 1] + min(neededTime[lastPicked], neededTime[i]);

                if(neededTime[lastPicked] < neededTime[i])
                    lastPicked = i;
            }
        }
        return dp[n - 1];
        */
    }
};
// @lc code=end
