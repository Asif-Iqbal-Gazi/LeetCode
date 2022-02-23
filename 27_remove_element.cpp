class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /* Approach1: Two pointer swap, take two pointers to both extreme, check if element at left pointer index == val, if yes swap with element at right pointer, decrese right pointer, now check if swapped element at left pointer is == val, if not increase left pointer.
        
        Approach2: Using vector library function
        distance(iterator1, iterator2)
        remove(iterator1, iterator2, value_to_remove) --> returns new end*/
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int l=0, n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]!=val){
                nums[l++]=nums[i];
            }
        }
        return l;
        /* Approach2
        return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
        */
    }
};