class Solution {
public:
    int strStr(string haystack, string needle) {
        /*
        Approach: Use library function find()
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int ans = 0;
        // Some sanity check
        if(needle.size()==0)
            return ans;
        ans = haystack.find(needle);
        if(ans != string::npos)
            return ans;
        return -1;
    }
};