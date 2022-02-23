class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /*
        Approach:
        1. Observe that our result container will be vector<vector<int>> type.
        2. Number of vectors in our container will be same as numRows
        3. For all vector inside our vector<vector<int>> container has 1 as extreme elements.
        4. Pre build row 1, if numRow==1 return it, else, pre build 2nd row {1,1} and then code the logic for building numRow >2 from previous row. This loop will only get executed if numRow>2
        */
        
        vector<vector<int>> result;
        
        // We know, numRow >=1
        result.push_back({1});
        
        // If numRows == 1 return result immediately
        if(numRows==1) return result;
        // Else if numRows >1 better to build second row as well.
        else{
            result.push_back({1,1});
        }
        
        // This loop will take effect if numRow > 2
        int i = 2; // If we have reached here, then we already have two rows
        while(i<numRows){
            // Create a new row with row+1 elements and fill them with '1'
            vector<int> currRow(i+1, 1);
            // Push it to result
            result.push_back(currRow);
            // We know, extreme elements will not change and remain '1' hence start from j=1
            for(int j=1; j<result[i-1].size(); j++)
                // Our array's 'j' positiion will be sum of elements{'j' & 'j-1'} from previous row {'i-1'}
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            // Finally increase our i to move on to next row
            i++;
        }
        
        return result;
    }
};