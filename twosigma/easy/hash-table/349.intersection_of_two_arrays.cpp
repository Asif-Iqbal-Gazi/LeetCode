/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        /*
        Approach 1 : Sort and Check using Two Pointers (O(nlogn + mlogm))
        Sort both the arrays, then using loop check element by element, if equal push them to the result array
        Approach 2 : Hash-map (O(n+m) but auxilary space(O(m+n)))
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        /* Approach 1
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0, j=0, n1=nums1.size(), n2=nums2.size();

        while(i<n1 && j<n2){
            if(nums1[i]>nums2[j])
                j++;
            else if(nums1[i]<nums2[j])
                i++;
            else{
                result.emplace_back(nums1[i]);
                i++;
                j++;
            }
        }
        return result;
        */

        // Approach 2
        vector<int> result;
        int n = nums1.size(), m = nums2.size();
        if (n > m)
            return intersection(nums2, nums1);
        unordered_set<int> set(nums1.begin(), nums1.end());

        for (int i = 0; i < m; i++)
        {
            if (set.find(nums2[i]) != set.end())
            {
                result.emplace_back(nums2[i]);
                set.erase(nums2[i]);
            }
        }
        return result;
    }
};
// @lc code=end
