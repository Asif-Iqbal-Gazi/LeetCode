impl Solution {
    pub fn third_max(nums: Vec<i32>) -> i32 {
        use std::i64::MIN;
        let (mut first, mut second, mut third) : (i64, i64, i64) = (MIN, MIN, MIN);

        for num in nums {
            let n = num as i64;

            if n == first || n == second || n == third {
                continue;
            }

            if n > first {
                third = second;
                second = first;
                first = n;
            } else if n > second {
                third = second;
                second = n;
            } else if n > third {
                third = n;
            }
        }

        if third == MIN {
            first as i32
        } else {
            third as i32
        }
    }
}
