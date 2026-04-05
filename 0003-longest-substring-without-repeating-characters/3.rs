use std::collections::HashMap;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        /*
         * Approach:
         * 1. Brute Force           -- T.C: O(N^2), S.C: O(N)
         *      - Check every possible substring for uniqueness.
         * 2. Sliding Window + Set  -- T.C: O(N),   S.C: O(N)
         *      - Expand right, shrink left on duplicate.
         * 3. Sliding Window + Map  -- T.C: O(N),   S.C: O(N)
         *      - Jump left directly to lastSeen[s[r]] + 1 on duplicate.
         */

        // Approach 3 -- Sliding Window + Map
        let mut last_seen: HashMap<char, usize> = HashMap::new();
        let     s_chars: Vec<char>              = s.chars().collect();
        let mut max_len                         = 0;
        let mut l                               = 0;
        for r in 0..s_chars.len() {
            if let Some(&idx) = last_seen.get(&s_chars[r]) {
                if idx >= l {
                    l = idx + 1;
                }
            }
            last_seen.insert(s_chars[r], r);
            max_len = max_len.max(r - l + 1);
        }
        max_len as i32

        /* Approach 2 -- Sliding Window + Set
        use std::collections::HashSet;
        let     s_chars: Vec<char> = s.chars().collect();
        let mut in_window          = HashSet::new();
        let mut max_len            = 0;
        let mut l                  = 0;
        for r in 0..s_chars.len() {
            while in_window.contains(&s_chars[r]) {
                in_window.remove(&s_chars[l]);
                l += 1;
            }
            in_window.insert(s_chars[r]);
            max_len = max_len.max(r - l + 1);
        }
        max_len as i32
        */

        /* Approach 1 -- Brute Force
        use std::collections::HashSet;
        let s_chars: Vec<char> = s.chars().collect();
        let n                  = s_chars.len();
        let mut max_len        = 0;
        for i in 0..n {
            let mut seen = HashSet::new();
            for j in i..n {
                if seen.contains(&s_chars[j]) { break; }
                seen.insert(s_chars[j]);
                max_len = max_len.max(j - i + 1);
            }
        }
        max_len as i32
        */
    }
}
