class Solution {
public:
    int findFirstOccurence(vector<int>& a, int target){
        int l = 0, h = a.size()-1, index = -1;
        while(l<=h){
            int m = l + (h-l)/2;
            if(a[m]>target)
                h = m - 1;
            else if(a[m]<target)
                l = m + 1;
            else{
                index = m;
                h = m - 1;
            }
        }
        return index;
    }
    
    int findLastOccurence(vector<int>& a, int target){
        int l = 0, h = a.size()-1, index = -1;
        while(l<=h){
            int m = l + (h-l)/2;
            if(a[m]>target)
                h = m - 1;
            else if(a[m]<target)
                l = m + 1;
            else{
                index = m;
                l = m + 1;
            }
        }
        return index;
    }
    
    vector<int> targetIndices(vector<int>& nums, int target) {
        /*
        Approach: 
        1. Sort the array.
        2. Use binary search to find the first occurenece
        3. Use binary search to find the last occurence
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        // Sort the array
        sort(nums.begin(), nums.end());
        vector<int> result;
        
        int first = findFirstOccurence(nums, target);
        int last = findLastOccurence(nums, target);
        
        if(first==-1 && last==-1)
            return result;
        while(first <= last)
            result.emplace_back(first++);
        
        return result;
    }
};