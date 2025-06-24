class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    // Approach 1 : Two Pointer
    int l   = 0;
    int pos = 0;
    int n   = nums.size();

    while (l < n) {
      if (nums[l] != val) nums[pos++] = nums[l];
      l++;
    }

    return pos;

    /** Approach 2: Using vector library function
      return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
     */
  }
};
