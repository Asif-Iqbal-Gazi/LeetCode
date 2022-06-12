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
        Approach 1:
        1. Have two sets to store the elements of nums1 and nums2.
        2. Then take any set and check elements of that set are present in other set.
        3. If so, add them in result

        Approach 2:
        1. Sort both the arrays
        2. Then using two pointer array push them in a set.
        3. From set finall build the result vector.
        */

        /* Approach 1
        vector<int> result;
        unordered_set<int> set1, set2;

        // Insert elements of num1 in set1
        for(int element: nums1)
            set1.insert(element);
        // Insert elements of num2 in set2
        for(int element: nums2)
            set2.insert(element);
        // Compare elements of set1 with set2
        for(auto it=set1.begin(); it!=set1.end(); it++){
            if(set2.find(*it) != set2.end())
                result.emplace_back(*it);
        }
        return result;
        */

        // Approach 2
        vector<int> result;
        unordered_set<int> set;
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();

        // Sort both the arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // Two pointer technique
        while (i < n && j < m)
        {
            if (nums1[i] > nums2[j])
                j++;
            else if (nums1[i] < nums2[j])
                i++;
            else
            {
                set.insert(nums1[i]);
                i++;
                j++;
            }
        }

        // Push integers from the set to the result vector
        for (auto it = set.begin(); it != set.end(); it++)
            result.emplace_back(*it);

        return result;
    }
};
// @lc code=end
