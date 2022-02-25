class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        Approach:
        1. After calculating mid find which side is not strictly increasing, that side will coantins our smallest element.
        2. We do so by comparing nums[m]>nums[r], if this is true, then right side is where we need to look, so we update l=m+1.
        3. However, if the previous comparison fails then it is on the right side. So we update r=m. (Why not m-1 ? Because, the element at mid might be the smallest element as well.)
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int l=0, r=nums.size()-1;
        while(l<r){
            int m = l + (r-l)/2;
            // Find the side which is not strictly increasing.
            if(nums[m]>nums[r])
                l = m + 1;
            else
                r = m;
        }
        return nums[l];
    }
};