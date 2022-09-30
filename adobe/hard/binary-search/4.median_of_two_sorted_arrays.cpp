/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        /* Approach :
            1. Bruteforce -- T.C: O(n+m), S.C: O(n+m)
            2. Binary Search -- T.C: O(log(min(n+m))), S.C: O(1)
        */

        /* Approach 1
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0, k = 0;
        vector<int> ds(n + m, 0);

        while (i < n && j < m)
        {
            if (nums1[i] < nums2[j])
                ds[k++] = nums1[i++];
            else
                ds[k++] = nums2[j++];
        }

        while (i < n)
            ds[k++] = nums1[i++];
        while (j < m)
            ds[k++] = nums2[j++];

        return (m + n) % 2 == 0 ? (ds[(m + n) / 2] + ds[(m + n) / 2 - 1]) / 2.0 : ds[(m + n) / 2];
        */

        // Approach 2
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size();
        int m = nums2.size();

        int l = 0, h = n;

        while (l <= h)
        {
            int cut1 = l + (h - l) / 2;
            int cut2 = (m + n + 1) / 2 - cut1; // (m+n+1) takes care of the odd case as well

            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int right1 = cut1 == n ? INT_MAX : nums1[cut1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int right2 = cut2 == m ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1)
            {
                // Valid Partition
                if ((m + n) % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else
                    return max(left1, left2);
            }
            else if (left1 > right2)
                h = cut1 - 1;
            else
                l = cut1 + 1;
        }
        return 0.0;
    }
};
// @lc code=end
