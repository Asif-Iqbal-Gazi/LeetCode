impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut triangle: Vec<Vec<i32>> = Vec::with_capacity(num_rows as usize);
        
        for row in 0..num_rows as usize {
            let mut curr = vec![1; row + 1];
            for col in 1..row {
                curr[col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
            }
            triangle.push(curr);
        }
        triangle
    }
}
