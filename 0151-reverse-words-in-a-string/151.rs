impl Solution {
    pub fn reverse_words(s: String) -> String {
        /* Approach:
         *      1. [C-Style Logical Implementation] -- T.C: O(N), S.C: O(N)
         */
        
        // Approach 2: Rust Idiomatic
        s.split_whitespace()
            .rev()
            .collect::<Vec<&str>>()
            .join(" ")

        /* Approach 1: C-Style Logical Implementation
        let mut chars: Vec<char> = s.chars().collect();

        // Remove extra spaces
        let mut write_pos = 0;
        let n = chars.len();
        let mut i = 0;

        while i < n {
            if chars[i] != ' ' || (i > 0 && chars[i - 1] != ' ') {
                chars[write_pos] = chars[i];
                write_pos += 1;
            }
            i += 1;
        }

        if write_pos > 0 && chars[write_pos - 1] == ' ' {
            write_pos -= 1;
        }
        chars.truncate(write_pos);

        // Reverse each word
        let mut i = 0;
        while i < chars.len() {
            let mut j = i;
            while j < chars.len() && chars[j] != ' ' {
                j += 1;
            }
            chars[i..j].reverse();
            i = j + 1;
        }

        // Reverse whole string
        chars.reverse();
        chars.into_iter().collect()
        */
    }
}
