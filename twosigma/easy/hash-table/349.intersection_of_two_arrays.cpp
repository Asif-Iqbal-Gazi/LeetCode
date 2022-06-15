/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        /*
        Approach :
        1. Sorting ans Two Pointers -- O(NlogN + MlogM), SC: O(max(N,M))
            Sort and Check using Two Pointers
        2. Unordered Set -- O(N+M), SC: O(min(M,N))
        */

        /* Sorting
        vector<int> result;
        unordered_set<int> s; // We need this to prevent duplication

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();

        while (i < n1 && j < n2)
        {
            if (nums1[i] == nums2[j])
            {
                if (s.find(nums1[i]) == s.end())
                    result.emplace_back(nums1[i]);
                s.insert(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return result;
        */

        // Unordered Set
        vector<int> result;
        int n1 = nums1.size(), n2 = nums2.size();
        // This line might save some step
        if (n1 < n2)
            return intersection(nums2, nums1);

        unordered_set<int> s(nums2.begin(), nums2.end());

        for (int i = 0; i < n1; i++)
        {
            if (s.find(nums1[i]) != s.end())
            {
                result.emplace_back(nums1[i]);
                s.erase(nums1[i]); // This will prevent duplicate
            }
        }
        return result;
    }
};
// @lc code=end
