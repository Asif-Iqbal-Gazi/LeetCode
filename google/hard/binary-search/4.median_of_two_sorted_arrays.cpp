/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        /*
        Approach 1:
        1. Create a new array of size(m+n)
        2. Find the median from that array

        Approach 2: Binary Search
        */

        /* Approach 1
        double result = 0;
        int i = 0, j = 0, k = 0, m = nums1.size(), n = nums2.size();
        vector<int> combined(m + n, 0);

        // Construct the combined array
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
                combined[k++] = nums1[i++];
            else
                combined[k++] = nums2[j++];
        }
        while (i < m)
        {
            combined[k++] = nums1[i++];
        }
        while (j < n)
        {
            combined[k++] = nums2[j++];
        }

        // Check the median.
        if ((m + n) % 2)
            result = combined[(m + n) / 2];
        else
            result = double(combined[(m + n) / 2] + combined[((m + n) / 2) - 1]) / 2;

        return result;
        */
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n1;
        while (l <= r)
        {
            int cut1 = l + (r - l) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
            // Corrrect Partition
            if (left1 <= right2 && left2 <= right1)
            {
                // Odd Case
                if ((n1 + n2) % 2)
                    return max(left1, left2);
                else
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else if (left1 > right2)
                r = cut1 - 1;
            else
                l = cut1 + 1;
        }
        return 0.0;
    }
};
// @lc code=end
