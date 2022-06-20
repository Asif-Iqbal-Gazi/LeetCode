/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        /* Approach
        1. Bruteforce : T.C: O(N*M), S.C: O(1)
        2. Stack + Unordered_Map: T.C: O(M+N), S.C : O(M)
            The problem statement states that "distinct 0-indexed integer array"
            Thus we can prepare an unordered map of nextGreater element using stack.
            Then in one traversal of nums1 we can output result from the map
        */

        // Approach 2
        int n = nums1.size(), m = nums2.size();

        stack<int> st;
        vector<int> ans(n, -1);
        unordered_map<int, int> map;

        // Building "nextGreater" using stack
        st.push(nums2[m - 1]);
        map[nums2[m - 1]] = -1;
        for (int i = m - 2; i >= 0; i--)
        {
            while (!st.empty() && nums2[i] >= st.top())
                st.pop();
            map[nums2[i]] = st.empty() == true ? -1 : st.top();
            st.push(nums2[i]);
        }

        // Traverse nums1
        for (int i = 0; i < n; i++)
            ans[i] = map[nums1[i]];
        return ans;

        /* Approach 1
        vector<int> ans;

        for (int x : nums1)
        {
            // Find the element in nums2 array
            int i = 0;
            while (i < nums2.size() && nums2[i] != x)
                i++;
            // Since, we are out of above loop currenlty nums2[i] == x;
            // Now let's find next greater element
            while (i < nums2.size() && nums2[i] <= x)
                i++;
            // By this time either i == nums2.size() or i points to next greater element
            int res = (i == nums2.size() ? -1 : nums2[i]);
            ans.emplace_back(res);
        }
        return ans;
        */
    }
};
// @lc code=end
