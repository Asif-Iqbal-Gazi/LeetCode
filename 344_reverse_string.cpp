class Solution {
public:
    void reverseString(vector<char>& s) {
        /*
        Approach: Two Pointer
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = s.size();
        int i = 0, j = n-1;
        while(i<j){
            swap(s[i++],s[j--]);
        }
        
    }
};