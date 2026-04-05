impl Solution {
    fn expand(s: &[u8], mut l: i32, mut r: i32) -> (i32, i32) {
        while l >= 0 && r < s.len() as i32 && s[l as usize] == s[r as usize] {
            l -= 1;
            r += 1;
        }
        (l + 1, r - l - 1)
    }

    pub fn longest_palindrome(s: String) -> String {
        /*
         * Approach:
         * 1. Brute Force            -- T.C: O(N^3), S.C: O(1)
         *      - Check every substring for palindrome property.
         * 2. Dynamic Programming    -- T.C: O(N^2), S.C: O(N^2)
         *      - dp[i][j] = true if s[i..j] is a palindrome.
         * 3. Expand Around Center   -- T.C: O(N^2), S.C: O(1)
         *      - Expand outward from each center for odd and even lengths.
         * 4. Manacher's Algorithm   -- T.C: O(N),   S.C: O(N)
         *      - Use previously computed radii to skip redundant comparisons.
         */

        // Approach 3 -- Expand Around Center
        let     s_bytes = s.as_bytes();
        let     n       = s_bytes.len() as i32;
        let mut start   = 0;
        let mut max_len = 1;

        for i in 0..n {
            let (l1, len1) = Self::expand(s_bytes, i, i);
            let (l2, len2) = Self::expand(s_bytes, i, i + 1);
            if len1 > max_len { max_len = len1; start = l1; }
            if len2 > max_len { max_len = len2; start = l2; }
        }
        s[start as usize..(start + max_len) as usize].to_string()

        /* Approach 4 -- Manacher's Algorithm
        let s_bytes = s.as_bytes();
        let n       = s_bytes.len();
        let mut t   = vec![b'#'; 2 * n + 1];
        for i in 0..n { t[2 * i + 1] = s_bytes[i]; }
        let m       = t.len();
        let mut p   = vec![0i32; m];
        let mut c   = 0i32;
        let mut r   = 0i32;
        for i in 0..m as i32 {
            let mirror = 2 * c - i;
            if i < r { p[i as usize] = p[mirror as usize].min(r - i); }
            while i + p[i as usize] + 1 < m as i32 &&
                  i - p[i as usize] - 1 >= 0 &&
                  t[(i + p[i as usize] + 1) as usize] ==
                  t[(i - p[i as usize] - 1) as usize] {
                p[i as usize] += 1;
            }
            if i + p[i as usize] > r { c = i; r = i + p[i as usize]; }
        }
        let max_len = *p.iter().max().unwrap();
        let center  = p.iter().position(|&x| x == max_len).unwrap() as i32;
        let start   = (center - max_len) / 2;
        s[start as usize..(start + max_len) as usize].to_string()
        */
    }
}
