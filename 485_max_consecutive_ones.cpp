class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        /*Approach : Take two varibale count and result
        Now, iterate over the array.
        If the element is '1' increment count and set result to max(count, result)
        Else if, the element is '0' set count to '0'*/
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        int result =0, count  = 0;
        for(int i=0; i<n; i++){
            if(nums[i]){
                count++;
                result = max(result, count);
            }
            else{
                count = 0;
            }
        }
        return result;
    }
};