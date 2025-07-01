impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {

        let (rows, cols) = (matrix.len(), matrix[0].len());
        // let mut res = Vec::with_capacity(m * n);
        let mut res = vec![0; rows * cols];
        let (mut index, mut direction) = (0, 0);
        let (mut left, mut right, mut up, mut down) = (0, cols - 1, 0, rows - 1);

        while index < rows * cols {
            if direction == 0 {
                // Traverse right
                for col in left..=right {
                    res[index] = matrix[up][col];
                    index += 1;
                }
                // Change direction to down
                direction = 1;
                up += 1;
            } else if direction == 1 {
                // Traverse down
                for row in up..=down {
                    res[index] = matrix[row][right];
                    index += 1;
                }
                // Change direction to left
                direction = 2;
                right -= 1;
            } else if direction == 2 {
                // Traverse left
                for col in (left..=right).rev() {
                    res[index] = matrix[down][col];
                    index += 1;
                }
                // Change direction to up
                direction = 3;
                down -= 1;
            } else {
                // Traverse up
                for row in (up..=down).rev() {
                    res[index] = matrix[row][left];
                    index += 1;
                }
                // Change direction to right
                direction = 0;
                left += 1;
            }
        }

        res
    }
}
