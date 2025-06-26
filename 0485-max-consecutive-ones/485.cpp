class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    /* Approach :
       1. [Two Pointer] -- T.C: O(N), S.C: O(1)
        - Traverse array and count consecutive ones, resetting count on 0, tracking the maximum
    */

    int res        = 0;
    int curr_count = 0;
    for (int num : nums) {
      if (num) {
        curr_count++;
        res = curr_count > res ? curr_count : res;
      } else
        curr_count = 0;
    }
    return res;
  }
};
