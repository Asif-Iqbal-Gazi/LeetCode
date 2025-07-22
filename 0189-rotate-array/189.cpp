class Solution {
private:
  void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
      int temp    = nums[start];
      nums[start] = nums[end];
      nums[end]   = temp;
      start++;
      end--;
    }
  }

public:
  void rotate(vector<int>& nums, int k) {
    /* Approach:
     *  1. [Reverse In-Place] -- T.C: O(N), S.C: O(1)
     *      - Rotating the array right by k is equivalent to:
     *          a) Reverse first n - k elements
     *          b) Reverse last k elements
     *          c) Reverse the entire array
     *      - Example: n = 7, k = 3
     *          Original:   1 2 3 4 5 6 7
     *          Step 1:     4 3 2 1 5 6 7   (reverse first 4)
     *          Step 2:     4 3 2 1 7 6 5   (reverse last 3)
     *          Step 3:     5 6 7 1 2 3 4   (reverse all)
     */

    int n = nums.size();
    k %= n;
    if (k == 0)
      return;
    reverse(nums, 0, n - k - 1);
    reverse(nums, n - k, n - 1);
    reverse(nums, 0, n - 1);
  }
};
