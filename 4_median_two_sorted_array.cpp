class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        /*
        Approach 1:
        1. Create a new array of size(m+n)
        2. Find the median from that array
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

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
    }
};