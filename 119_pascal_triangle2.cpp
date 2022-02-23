class Solution {
public:
    vector<int> getRow(int rowIndex) {
        /*
        Approach:
        Observe the pascal's triangle like this:
        1
        1 1
        1 2 1
        1 3 3 1
        1 4 6 4 1
        
        1. Take a res vector with size = rowIndex+1 (Cause we have 0 Index) and set all it's value to 1
        2. If rowIndex < 2 return res directly
        3. Notice that for elements at any row for position [1, rowIndex-1] is actually the sum of element at same and previous position in the previous row
        
        Example: For rowIndex = 4
        [1,1,1,1,1] --> rowIndex = 4
        [1,2,3,4,1] --> rowIndex = 3
        [1,3,3,4,1] --> rowIndex = 2
        [1,4,6,4,1] --> rowIndex = 1
        
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        // Our result vector
        vector<int> res(rowIndex+1, 1);
        // If rowIndex is less than 2 return immediately (cause, they only have 1's)
        if(rowIndex < 2)
            return res;
        // Our first pointer
        int j = rowIndex; 
        while(rowIndex>=2){
            for(int i=1; i<rowIndex; i++){
                res[i] = res[i] + res[i-1];
            }
            rowIndex--;
        }
        return res;
    }
};