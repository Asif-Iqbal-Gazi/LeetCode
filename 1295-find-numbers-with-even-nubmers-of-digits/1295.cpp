class Solution {
  public:
    int findNumbers(vector<int>& nums) {
        int count = 0;

        for (int num : nums) {
            int digitCount = 0;

            while (num) {
                digitCount++;
                num /= 10;
            }

            if (digitCount % 2 == 0)
                count++;
        }
        return count;
    }
};
