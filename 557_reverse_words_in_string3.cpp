class Solution {
public:
    string reverseWords(string s) {
        /*
        Approach:
        1. Take a pointer position and set it at 0 initially
        2. Now traverse the string starting from 0 and look for space char.
        3. When found use reverse(s.begin()+position, s.begin()+i) to reverse the word
        4. Update position=i+1 (Remember during above reversal our i was pointing to ' ' char, so + 1)
        5. Once we have finished our traversal we would have reversed all words except the last one as it doesn't have a ' ' char at the end.
        6. To tackle this use reverse(s.begin()+position, s.end())
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int len = s.size();
        int position = 0;
        // This loop will reverse all words except the last one
        for(int i=0; i<len; i++){
            if(s[i]==' '){
                reverse(s.begin()+position, s.begin()+i);
                position = i + 1;
            }
        }
        // Dealing with the last word
        reverse(s.begin()+position, s.end());
        
        return s; 
    }
};