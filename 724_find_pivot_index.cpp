class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        /*
        Approach: LeftSum == RightSum
        1. First calculate the total sum and set it to rightSum
        2. Then inside the loop, substract current element from rSum and check if it is equal to lSum, if yes, then return the current index else add current element to lSum and move to next iteration.
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int lSum=0, rSum=0, n=nums.size();
        // First find the total sum
        for(int i=0; i<n; i++){
            rSum += nums[i];
        }
        
        // Check lSum & sSum
        for(int i=0; i<n; i++){
            // Update rSum
            rSum -= nums[i];
            // Check both the sums are equal
            if(rSum==lSum)
                return i;
            // Update lSum
            lSum += nums[i]; 
        }
        
        return -1;
        
    }
};