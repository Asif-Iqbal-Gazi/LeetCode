/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        /*
        Approach 1 : Sort and Check using Two Pointers (O(nlogn + mlogm))
            Sort both the arrays, then using loop check element by element, if equal push them to the result array
        Approach 2 : Hash-map (O(n+m) but auxilary space(O(min(m,n)))
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
            return intersect(nums2, nums1);
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            map[nums1[i]]++;
        }

        for (int i = 0; i < m; i++)
        {
            if (map.find(nums2[i]) != map.end())
            {
                result.emplace_back(nums2[i]);
                if (map[nums2[i]] == 1)
                    map.erase(nums2[i]);
                else
                    map[nums2[i]]--;
            }
        }
        return result;
    }
};
// @lc code=end
