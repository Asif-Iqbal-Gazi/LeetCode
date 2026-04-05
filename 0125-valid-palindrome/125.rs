impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        /*
         * Approach:
         * 1. Two Pointers -- T.C: O(N), S.C: O(1)
         *      - Use two pointers, skip non-alphanumeric, compare lowercase.
         * 2. String Filtering -- T.C: O(N), S.C: O(N)
         *      - Build filtered lowercase string and compare with reverse.
         */

        // Approach 1 -- Two Pointers
        let bytes = s.as_bytes();
        let mut l: i32 = 0;
        let mut r: i32 = (bytes.len() as i32) - 1;

        while l < r {
            while l < r && !bytes[l as usize].is_ascii_alphanumeric() {
                l += 1;
            }
            while l < r && !bytes[r as usize].is_ascii_alphanumeric() {
                r -= 1;
            }

            if bytes[l as usize].to_ascii_lowercase() != bytes[r as usize].to_ascii_lowercase() {
                return false;
            }

            l += 1;
            r -= 1;
        }

        true

        /* Approach 2 -- String Filtering
        let t: Vec<char> = s
            .chars()
            .filter(|c| c.is_ascii_alphanumeric())
            .map(|c| c.to_ascii_lowercase())
            .collect();

        let mut l = 0;
        let mut r = t.len().saturating_sub(1);

        while l < r {
            if t[l] != t[r] {
                return false;
            }
            l += 1;
            r -= 1;
        }

        true
        */
    }
}
