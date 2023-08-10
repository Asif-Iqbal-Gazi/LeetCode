/*
    2790. Maximum Number of Groups With Increasing Length
    https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length/description/
*/

class Solution {
   private:
    bool isPossible(int k, vector<int>& nums) {
        // Nums if sorted in increasing order
        // Kth group will have k elements, to check if k groups are possible or not
        // We will distribute nums[n - 1] to k buckets
        // Then nums[n - 2] to k - 1 buckets
        // Required varible will keep track of how many elements are required to fill k buckets
        int n = nums.size();
        int required = 0;
        for (int i = 0; i < n && k; i++) {
            if (k) required += k--;
            required -= min(required, nums[n - 1 - i]);
        }
        return required == 0;
    }

   public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        /* Approach:
            1. Binary Search on Answer -- T.C: O(n * log(n)), S.C: O(1)
        */

        // Approach 1 -- Binary Search on Answer
        // Observation:
        // -- If we sort the array then there is no loss of generality
        // -- We can verify if k no of group is possible or not in O(n) time

        int n = usageLimits.size();
        sort(usageLimits.begin(), usageLimits.end());

        // Because the group each group contains unqiue elements
        // We know that we can't have more than n groups
        int low = 1, high = n + 1;
        // 1 1 1 0 0 0 0 0 0
        // We want to find max i for which isPossible(i, usageLimits) == true
        // isPossible(l, usageLimits) == true
        // isPossible(h, usageLimits) == false
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, usageLimits))
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};