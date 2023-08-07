/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution {
   private:
    int noOfSubArraysAtmostKOdds(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int l = 0, r = 0;

        while (r < n) {
            if (nums[r] % 2)
                k--;
            r++;

            while (k < 0) {
                if (nums[l] & 1)
                    k++;
                l++;
            }
            ans += r - l;
        }
        return ans;
    }

   public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        /* Approach:
            1. BruteForce -- T.C: O(n^2), S.C: O(1)
            2. Prefix Sum + Unordered Map -- T.C: O(n), S.C: O(n)
                -- For odd elements we add 1, for even elements we add 0
                -- Then we find the number of subarrays with sum == k
            3. Sliding Window (Atleast Sum) -- T.C: O(n), S.C: O(1)
                -- Here, we are finding the number of subarrays with sum >= k
                -- Then, we are finding the number of subarrays with sum >= k + 1
                -- Then, we are subtracting the two to get the number of subarrays with sum == k
            4. Sliding Window (Atmost Sum) -- T.C: O(n), S.C: O(1)
                -- Here, we are finding the number of subarrays with sum <= k
                -- Then, we are finding the number of subarrays with sum <= k - 1
                -- Then, we are subtracting the two to get the number of subarrays with sum == k
            5. Same as above but using single pass -- T.C: O(n), S.C: O(1)
        */

        // Approach 5 -- Single Pass (Atmost K)
        int ans = 0;
        int n = nums.size();
        int l = 0, r = 0, count = 0;

        while (r < n) {
            if (nums[r] & 1) {
                k--;
                count = 0;
            }

            while (k == 0) {
                /* Explanation:
                    Once we have found a subarray with k odd elements,
                    We can find the number of subarrays with atmost k odd elements
                    We can do this by incrementing the left pointer until we have k odd elements
                    The count variable will keep track of the number of subarrays with atmost k odd elements
                */
                if (nums[l] & 1)
                    k++;
                l++;
                count++;
            }
            ans += count;
            r++;
        }
        return ans;

        /* Approach 4 -- Sliding Window (Atmost Sum)
        return noOfSubArraysAtmostKOdds(nums, k) - noOfSubArraysAtmostKOdds(nums, k - 1);
        */

        /** Approach 3 -- Sliding Window (Atleast Sum)
        int n = nums.size();
        int ans1 = 0, ans2 = 0;

        int l1 = 0, l2 = 0, r = 0;
        int oddCountOne = 0;
        int oddCountTwo = 0;

        while (r < n) {
            if (nums[r] & 1) {
                oddCountOne++;
                oddCountTwo++;
            }
            r++;

            while (l1 < r && oddCountOne >= k) {
                ans1 += n - r + 1;
                if (nums[l1] & 1)
                    oddCountOne--;
                l1++;
            }

            while (l2 < r && oddCountTwo >= k + 1) {
                ans2 += n - r + 1;
                if (nums[l2] & 1)
                    oddCountTwo--;
                l2++;
            }
        }
        return ans1 - ans2;
        */

        /* Approach 2 -- Prefix Sum + Map
        int ans = 0;
        int n = nums.size();
        int runningSum = 0;

        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;

        for (int i = 0; i < n; i++) {
            runningSum += nums[i] % 2;
            if (prefixSum.count(runningSum - k))
                ans += prefixSum[runningSum - k];
            prefixSum[runningSum]++;
        }
        return ans;
        */

        /* Approach 1 -- BruteForce
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int oddCount = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2)
                    oddCount++;
                if (oddCount == k)
                    ans++;
                else if (oddCount > k)
                    break;
            }
        }
        return ans;
        */
    }
};
// @lc code=end
