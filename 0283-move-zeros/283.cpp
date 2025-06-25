class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    /** Approach:
      First using a pointer fill in the non-zero elements.
      Then finally fill the rest of the vector with zeros.
    */

    int pos = 0;
    int n   = nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] != 0) nums[pos++] = nums[i];
    }

    while (pos < n) nums[pos++] = 0;
  }
};
