impl Solution {
    pub fn reverse_bits(x: i32) -> i32 {
        // Approach: 
        //  Bit Manipulation -- T.C: O(1), S.C: O(1)
        //  Rusty -- T.C: O(1), S.C: O(1)

        // Bit Manipulation
        let mut res: i32 = 0;
        for i in 0..32 {
            let bit = (x >> i) & 1;
            res |= bit << (31 - i);
        }
        res

        // Rusty
        //x.reverse_bits()
    }
}
