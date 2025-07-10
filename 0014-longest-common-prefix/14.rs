impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut prefix_len = strs[0].len();
        let first = strs[0].as_bytes();

        for s in &strs[1..] {
            let curr_s_bytes = s.as_bytes();
            let mut j  = 0;
            while j < prefix_len && j < curr_s_bytes.len() && curr_s_bytes[j] == first[j] {
                j += 1;
            }
            prefix_len = j;
            if prefix_len == 0 {
                break;
            }
        }

        strs[0][..prefix_len].to_string()
    }
}
