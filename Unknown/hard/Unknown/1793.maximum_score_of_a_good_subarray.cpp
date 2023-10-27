/*
 * @lc app=leetcode id=1793 lang=cpp
 *
 * [1793] Maximum Score of a Good Subarray
 */

// @lc code=start
class Solution {
   public:
    int maximumScore(vector<int>& nums, int k) {
        /* Approach:
            1. Monotonic Stack -- T.C: O(N), S.C: O(N)
            2. Greedy -- T.C: O(N), S.C: O(1)
        */

        // Approach 2 -- Greedy
        /* Observation
            Our good subarray must contain nums[k]
            So, we will keep two pointers 'l' & 'r' and keep on expanding our window
            It can argued that, to decide which pointer to move, we check which gives greater value:
                nums[l] or nums[r]
            As we have are concerned with 'minimum' value in our window, we can do this
        */

        int n = nums.size();
        int l = k, r = k, res = nums[k], currMin = nums[k];

        int leftVal = 0;
        int rightVal = 0;
        while (l > 0 || r < n - 1) {
            leftVal = l > 0 ? nums[l - 1] : 0;
            rightVal = r < n - 1 ? nums[r + 1] : 0;

            if (leftVal > rightVal) {
                l--;
                currMin = min(currMin, leftVal);
            } else {
                r++;
                currMin = min(currMin, rightVal);
            }
            res = max(res, currMin * (r - l + 1));
        }

        return res;

        // Approach 1 -- Monotonic Stack
        /* Idea:
            Considering each element as minimum find a window for that element
            Using next greater and previous greater element
        */
        /*
        int n = nums.size();
        vector<int> prev(n, -1);
        vector<int> next(n, n);

        vector<int> st;
        // Calculate previous greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] > nums[i]) {
                prev[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }

        st.clear();

        // Calculate next greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.back()] > nums[i]) {
                next[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (prev[i] < k && next[i] > k)
                ans = max(ans, nums[i] * (next[i] - prev[i] - 1));
        }

        return ans;
        */
    }
};
// @lc code=end
