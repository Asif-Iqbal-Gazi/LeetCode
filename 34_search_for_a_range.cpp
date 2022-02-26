class Solution {
    int lower_bound(vector<int>& a, int x){
        int n = a.size();
        int lower_bound = n;
        int l = 0, r = n-1;
          
        while(l<=r){
            int m = l + (r-l)/2;
            if(a[m]>=x){
                lower_bound = m;
                r = m-1;
            }
            else
                l = m+1;
        }
        return lower_bound;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
        Approach 1:
        1. First find whether the element exist, if it exist then get it's index.
        2. Next have lBound and rBound variable and using while loop find them.
        
        Approach 2:
        1. Find the lower bound by modifying Bianry Search.
        2. To do that, after calculating mid find if nums[m]>=target, if so, save this position in lBound and set r = m-1, so that we can find the first occurence.
        3. Else(when nums[m]<target) we know that we have to look in the right side, so we update l = m+1.
        4. Now this is tricky but we can find the upper bound using same method but instead of searching for target, we will search for target + 1. (Our nums[m]>=target) guarantees if there is any element greater than target it will be captured.
        
        Approach 3:
        Use library function lower_bound(nums.begin(),nums.end(),target);
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int first = lower_bound(nums, target);
        int last = lower_bound(nums, target+1) - 1; // Minus -1 because, it returns first pos of target+1, so last occurence of target will be at minus 1
        if(first<=last)   
            return {first, last};
        return {-1,-1};
          
    }
};