/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
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
private:
    void merge(vector<int> &nums, int l, int m, int r)
    {
        auto const subArrayOne = m - l + 1;
        auto const subArrayTwo = r - m;

        // Creating temp arrays
        auto *leftArray = new int[subArrayOne];
        auto *rightArray = new int[subArrayTwo];

        // Copy elements to temp arrays
        for (int i = 0; i < subArrayOne; i++)
            leftArray[i] = nums[l + i];
        for (int j = 0; j < subArrayTwo; j++)
            rightArray[j] = nums[m + 1 + j];

        // Indices required for merging
        int indexOfSubArrayOne = 0;
        int indexOfSubArrayTwo = 0;
        int indexOfMergedArray = l;

        // Main merging logic
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
        {
            if (leftArray[indexOfSubArrayOne] < rightArray[indexOfSubArrayTwo])
                nums[indexOfMergedArray++] = leftArray[indexOfSubArrayOne++];
            else
                nums[indexOfMergedArray++] = rightArray[indexOfSubArrayTwo++];
        }

        // Copy remaining elements
        while (indexOfSubArrayOne < subArrayOne)
            nums[indexOfMergedArray++] = leftArray[indexOfSubArrayOne++];
        while (indexOfSubArrayTwo < subArrayTwo)
            nums[indexOfMergedArray++] = rightArray[indexOfSubArrayTwo++];

        // Delete the temp arrays
        delete[] leftArray;
        delete[] rightArray;
    }
    void mergeSort(vector<int> &nums, int l, int r)
    {
        // Base Case
        if (l >= r)
            return;

        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        /* Approach:
            1. Using Recursive Merge Sort -- T.C: O(NlogN)
        */

        int l = 0;
        int r = nums.size() - 1;
        mergeSort(nums, l, r);
        return nums;
    }
};
// @lc code=end
