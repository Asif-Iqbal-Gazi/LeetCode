/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
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
    int findDuplicate(vector<int> &nums)
    {
        /*
        Approach 1: Hashmap
        1. While looping check if already in hash, if yes then return. Else add into hash.

        Approach 2: Index technique
        1. While looping take the element as index and set the element at that index as -ve. However if that element is already negative return that as result.
        */

        /* Approach 1
        int i = 0, n = nums.size();
        vector<int> hash(n, 0);

        while(i<n){
            if(hash[nums[i]]!=0)
                return nums[i];
            else
                hash[nums[i++]]++;
        }
        return -1;
        */
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int val = abs(nums[i]);
            if (nums[val] < 0)
                return val;
            else
                nums[val] = -nums[val];
        }
        return -1;
    }
};
// @lc code=end
