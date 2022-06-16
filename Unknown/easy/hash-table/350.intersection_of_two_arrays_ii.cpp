/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
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
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        /*
        Approach
        1 : Sort and Check using Two Pointers -- (O(nlogn + mlogm))
            Sort both the arrays, then using loop check element by element, if equal push them to the result array
        2 : Unordered_Map -- O(n+m), SC: O(min(m,n))
        */

        /* Sorting & Two Pointer
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();

        while (i < n1 && j < n2)
        {
            if (nums1[i] > nums2[j])
                j++;
            else if (nums1[i] < nums2[j])
                i++;
            else
            {
                result.emplace_back(nums1[i]);
                i++;
                j++;
            }
        }
        return result;
        */

        // Using Unordered_Map
        int n = nums1.size(), m = nums2.size();
        // For Optimal Space Complexity
        if (m < n)
            return intersect(nums2, nums1);

        vector<int> result;
        unordered_map<int, int> map;

        // Building the Map
        for (int i = 0; i < n; i++)
            map[nums1[i]]++;

        // Traversing the second array
        for (int i = 0; i < m; i++)
        {
            auto it = map.find(nums2[i]);
            if (it != map.end())
            {
                // Found Match
                if (it->second == 1)
                    // Frequency is 1 so removing it.
                    map.erase(it);
                else
                    // Frequency greater than '1' so decrement it
                    map[nums2[i]]--;
                result.emplace_back(nums2[i]);
            }
        }
        return result;
    }
};
// @lc code=end
