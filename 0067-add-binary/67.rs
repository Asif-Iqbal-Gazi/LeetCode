impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let (len_a, len_b) = (a.len(), b.len());
        let max_len = len_a.max(len_b);
        let mut res = vec!['0'; max_len + 1];
        let (a_bytes, b_bytes) = (a.as_bytes(), b.as_bytes());
        let (mut i, mut j, mut k) = (len_a as i32 - 1, len_b as i32 - 1, max_len as i32);
        let mut carry = 0;

        while i >= 0 || j >= 0 || carry > 0 {
            let mut total = carry;
            if i >= 0 {
                total += (a_bytes[i as usize] - b'0') as u8;
                i -= 1;
            }
            if j >= 0 {
                total += (b_bytes[j as usize] - b'0') as u8;
                j -= 1;
            }
            res[k as usize] = ((total % 2) + b'0') as char;
            carry = total / 2;
            k -= 1;
        }

        // Skip leading zero if not needed
        res[(k + 1) as usize..].iter().collect()
    }
}

