/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution {
   private:
    const int MOD = 1e9 + 7;

   public:
    int sumSubarrayMins(vector<int>& arr) {
        /* Approach:
            1. Stack -- T.C: O(n), S.C: O(n)
                -- at an index 'i', find all subarrays that includes arr[i] as minimum value
                -- To do so, we can find the index of the previous smaller element < arr[i], say such element's index is j
                   then, the number of subarrys that ends at i and have minimum value as arr[i] is (i - j)
                -- Similarly, we can find the index of the next smaller element < arr[i], say such element's index is k
                   then, the number of subarrys that starts at i and have minimum value as arr[i] is (k - i)
                -- So, the total number of subarrays that includes arr[i] as minimum value is (i - j) * (k - i)
                -- So, the total sum of all subarrays that includes arr[i] as minimum value is arr[i] * (i - j) * (k - i)
            2. Same as above (Single Pass) -- T.C: O(n), S.C: O(n
        */

        // Approach 2
        int ans = 0;
        int n = arr.size();
        stack<int> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] > arr[i])) {
                int j = st.top();   // If arr[j] > arr[i], then arr[i] is the next smaller element for arr[j]
                int right = i - j;  // Contribution of right elements
                st.pop();
                int left = (st.empty() ? j + 1 : j - st.top());  // Contribution of left elements
                ans = (ans + (1LL * arr[j] * left * right) % MOD) % MOD;
            }
            st.push(i);
        }
        return ans;

        /* Approach 1
        int n = arr.size();
        vector<int> minContributions(n, 1);
        stack<int> st;

        // Find the index of the previous and next smaller element for each element
        // We will maintain a monotonic increasing stack
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int j = st.top();  // If arr[j] > arr[i], then arr[i] is the next smaller element for arr[j]
                // Contribution of right elements
                minContributions[j] *= (i - j);
                st.pop();
            }
            // Contribution of left elements
            minContributions[i] *= (st.empty() ? i + 1 : i - st.top());
            st.push(i);
        }

        // Now, we might haev elements left in the stack (which means they don't have any next smaller element)
        // So, we will pop them and update their contribution (next smaller element is n)
        while (!st.empty()) {
            int j = st.top();
            minContributions[j] *= (n - j);
            st.pop();
        }

        // Now, we have the contribution of each element
        // We can calculate the sum of all subarrays that includes arr[i] as minimum value
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + (1LL * arr[i] * minContributions[i]) % MOD) % MOD;
        }

        return ans;
        */
    }
};
// @lc code=end
