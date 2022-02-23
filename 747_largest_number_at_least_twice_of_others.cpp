class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        /*
        Approach:
        1. Using one loop find both the largest and second largest number.
        2. Check if the largest is at least twice as much as second largest.
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int max = 0, secondMax=0, n = nums.size(), resIndex=0;
        
        // Special case
        if(n==1)
            return 0;
        
        // Find the max & second max
        for(int i=0; i<n; i++){
            if(max<nums[i]){
                resIndex = i;
                secondMax = max;
                max = nums[i];
            }
            else if(secondMax<nums[i] && nums[i]<max)
                secondMax = nums[i];
        }
        
        // If the max is greater than equal secondMax then it will be greater than all others
        if(max>=2*secondMax)
            return resIndex;
        return -1;
        
        
    }
};