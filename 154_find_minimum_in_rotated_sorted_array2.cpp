class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        Approach:
        1. After calculating mid find which side is not strictly increasing, that side will contains our smallest element.
        2. We do so by comparing nums[m]>nums[h], if this is true, then right side is where we need to look, so we update l=m+1.
        3. Else, if nums[m]<nums[h], then set h = m. (Why not m-1 ? Because, the element at mid might be the smallest element as well.)
        4. If both the condition above fails that would imply nums[m] == num[h], imagine an array [3,3,3,1,3] here, we have nums[m] == nums[h] so, what we can do is decrement h once and then calculate the mid and check again.
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int l = 0, h = nums.size()-1;
        while(l<h){
            int m = l + (h-l)/2;
            // Check if right side is decreasing
            if(nums[m]>nums[h])
                l = m + 1;
            else if(nums[m]<nums[h])
                h = m;
            else
                h--;
        }
        return nums[l];
    }
};