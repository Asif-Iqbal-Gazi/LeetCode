/*
    2799. Count Complete Subarrays in an Array
    https://leetcode.com/problems/count-complete-subarrays-in-an-array/
*/

class Solution {
   public:
    int countCompleteSubarrays(vector<int> &nums) {
        /* Approach:
            1. Bruteforce -- T.C: O(n^2), S.C: O(n)
            2. Sliding Window -- T.C: O(n), S.C: O(n)
        */

        // Approach 2 -- Sliding Window
        int ans = 0;
        int n = nums.size();
        int uniqueCount = 0;
        int freqMap[20001] = {0};
        // Get the number of unique elements
        for (int x : nums) {
            if (++freqMap[x] == 1) {
                uniqueCount++;
            }
        }
        // Reset the frequency map
        for (int x : nums) {
            freqMap[x] = 0;
        }

        int l = 0, r = 0;

        while (r < n) {
            if (++freqMap[nums[r]] == 1)
                uniqueCount--;

            while (uniqueCount == 0) {
                /* Logic:
                    Say our array is : [1,3,1,2,2]
                    Our l = 0, r = 3, uniqueCount = 3
                    So, ans += (n - r) = 5 - 3 = 2
                    Reason: Our 'r' pointer is at 3, and we have 3 unique elements,
                            Which is same as the number of unique elements in our array
                            Thus, even if we the (n - r) elements, we will still have 3 unique elements
                            So, no of subArrays that can be formed which starts with 'l' and has 3 unique elements is (n - r)
                */
                ans += n - r;
                if (--freqMap[nums[l]] == 0)
                    uniqueCount++;
                l++;
            }
            r++;
        }
        return ans;

        /* Approach 1 -- Bruteforce
        int ans = 0;
        int n = nums.size();
        unordered_set<int> unique;

        for (int x : nums)
            unique.insert(x);

        int uniqueCount = unique.size();

        for (int i = 0; i < n; i++) {
            unordered_set<int> s;
            for (int j = i; j < n; j++) {
                s.insert(nums[j]);
                if (s.size() == uniqueCount)
                    ans++;
                else if (s.size() > uniqueCount)
                    break;
            }
        }
        return ans;
        */
    }
};