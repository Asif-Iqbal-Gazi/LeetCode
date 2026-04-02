class Solution {
  public:
    int missingNumber(vector<int>& nums) {
        /* Approach 1: Bit Manipulation -- T.C: O(n), S.C: O(1) */
        int n          = nums.size();
        int missingNum = n;

        for (int i = 0; i < n; i++) missingNum ^= (i ^ nums[i]);

        return missingNum;
    }
};
