impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        /*
         * Approach:
         * 1. Hash Table -- T.C: O(N), S.C: O(1)
         *      - Count frequency of characters in s, decrement using t.
         *        If all counts are zero, strings are anagrams.
         * 2. Sorting -- T.C: O(N log N), S.C: O(1)
         *      - Sort both strings and compare.
         */

        // Approach 1 -- Hash Table
        if s.len() != t.len() {
            return false;
        }

        let mut count = vec![0; 26];

        for c in s.chars() {
            count[(c as u8 - b'a') as usize] += 1;
        }

        for c in t.chars() {
            count[(c as u8 - b'a') as usize] -= 1;
        }

        for c in count {
            if c != 0 {
                return false;
            }
        }

        true

        /* Approach 2 -- Sorting
        let mut s_chars: Vec<char> = s.chars().collect();
        let mut t_chars: Vec<char> = t.chars().collect();
        s_chars.sort();
        t_chars.sort();
        s_chars == t_chars
        */
    }
}
