class Solution {
public:
    int mySqrt(int x) {
        /*
        Approach: 
        1. Simple binary search.
        2. To avoid overflow make m = l + (h-l)/2 and during checking instead of m*m > x, do m > x/m instead.
        3. Finally, since we want to truncate result, before returning check if result* result > x, if so return result - 1.
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(x==0)
            return x;
        int l=1, h=x;
        while(l<h){
            int m = l + (h-l)/2;
            if(m == x/m)
                return m;
            else if(m < x/m)
                l = m+1;
            else
                h = m-1;
        }
        return (l > x/l) ? l-1 : l;
    }
};