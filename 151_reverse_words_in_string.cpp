class Solution {
public:
    string reverseWords(string s) {
        /*
        Approach:
        1. First remove all leading, trailing & extra spaces using two pointers.
        2. Now using string pop_back() function remove left over characters & trailing spaces (if any)
        3. Reverse the entire string.
        4. Reverse individual words. (Remember the last word my need extra trick to reverse)
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int index=0, l=0, r = s.size(), charToRemove=r-1;
        // Space Removal Part
        // Deal with leading, trailing & multiple spaces.
        while(l<r){
            if(s[l]!=' ' || ((l!=0)&&(s[l]==' ' && s[l-1]!=' '))){
                s[index] = s[l];
                index++;
            }
            l++;  
        }
        // Remove left over chars and trailing zero if any
        while(index <= charToRemove){
            s.pop_back();
            charToRemove--;
            if(index==charToRemove && s[index-1]==' ')
                s.pop_back();
        }
        
        // Reversing part
        // Reverse the entire string
        reverse(s.begin(), s.end());
        // Reverse the individual words, doesn't reverse the last word though
        r = s.size();
        index = 0;
        for(int i=0; i<r; i++){
            if(s[i]==' '){
                reverse(s.begin()+index, s.begin()+i);
                index = i+1;
            }
        }
        // Reverse the last word
        reverse(s.begin()+index, s.end());
        
        return s;
        
    }
};