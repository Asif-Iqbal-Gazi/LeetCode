/*
    2810. Faulty Keyboard
    https://leetcode.com/problems/faulty-keyboard/description/
*/

class Solution {
   public:
    string finalString(string s) {
        /* Approach:
            1. Linear Scan & Reverse -- T.C: O(n^2), S.C: O(1)
            2. Linear Scan & Deque -- T.C: O(n), S.C: O(n)
        */

        // Approach 2 -- Linear Scan & Deque
        deque<char> dq;
        bool flip = false;
        for (char c : s) {
            if (c == 'i')
                flip = !flip;
            else
                dq.insert(flip ? dq.begin() : dq.end(), c);
            /*
            else if (flip)
                dq.push_front(c);
            else
                dq.push_back(c);
            */
        }
        return flip ? string(dq.rbegin(), dq.rend()) : string(dq.begin(), dq.end());

        /* Approach 1 -- Linear Scan & Reverse
        string res;
        int i = 0, n = s.size();

        while (i < n) {
            if (s[i] != 'i') {
                res += s[i];
            }
            else {
                reverse(res.begin(), res.end());
            }
            i++;
        }
        return res;
        */
    }
};