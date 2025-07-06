impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        fn compute_lps(pattern: &[u8]) -> Vec<usize> {
            let m = pattern.len();
            let mut lps = vec![0; m];
            let mut len = 0;
            let mut i = 1;

            while i < m {
                if pattern[i] == pattern[len] {
                    len += 1;
                    lps[i] = len;
                    i += 1;
                } else if len > 0 {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i += 1;
                }
            }

            lps
        }

        let n = haystack.len();
        let m = needle.len();

        if m == 0 {
            return 0;
        }

        let haystack = haystack.as_bytes();
        let needle = needle.as_bytes();
        let lps = compute_lps(needle);

        let (mut i, mut j) = (0, 0);

        while i < n {
            if haystack[i] == needle[j] {
                i += 1;
                j += 1;
                if j == m {
                    return (i - m) as i32;
                }
            } else if j > 0 {
                j = lps[j - 1];
            } else {
                i += 1;
            }
        }

        -1
    }
}

