class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int index = 1, n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1])
                nums[index++] = nums[i];
        }
        return index;
    }
};