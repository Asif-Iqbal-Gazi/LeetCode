class Solution {
public:
    int myAtoi(string s) {
        /*
        Approach:
        1. First ignore the whitespace
        2. Deal with the sign
        3. Check if the character is in the range [0,9] if yes, extract digit and construct the number, else break
        */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
       
        int sign = 1, i = 0, res = 0, digit = 0, n = s.size();
        // Ignore whitespaces
        while(s[i] == ' ')
            i++;
        
        // Deal with sign
        if (s[i] == '-' or s[i] == '+') {
            sign = (s[i++] == '-') ? -1 : 1;
        }
        
        // Main loop to deal with character extraction and number construction
        while (i < n) {
            // Extract digit
            digit = s[i] - '0';
            // If not in the valid range 
            if (digit < 0 || digit > 9)
                break;
            // Check for out of range
            if ((res > INT_MAX/10) || (res == INT_MAX/10 && digit > INT_MAX%10))
                return (sign == -1) ? INT_MIN : INT_MAX;
            // Construct the result
            res = 10 * res + digit;
            i++;
        }
        
        return sign*res;
    }
};