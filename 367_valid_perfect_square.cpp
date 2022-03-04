class Solution {
public:
    bool isPerfectSquare(int num) {
        /*
        Approach:
        Perform a binray search in the range from (1, num) and check if (m*M==num) if so return true else modify the l or r accordingly.
        */
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        long int l=1, r=num;
        while(l<=r){
            long int m = l + (r-l)/2;
            if(m*m == num){
                return true;
            }
            else if(m*m > num)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
};