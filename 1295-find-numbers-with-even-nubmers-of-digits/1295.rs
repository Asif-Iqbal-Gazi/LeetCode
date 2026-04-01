impl Solution {
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        let (mut count, mut digit_count) = (0, 0);

        for mut num in nums {
            digit_count = 0;

            while num != 0 {
                digit_count += 1;
                num /= 10;
            }

            if digit_count % 2 == 0 {
                count += 1
            }
        }
        count 
    }
}
