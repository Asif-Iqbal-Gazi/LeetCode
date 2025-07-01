class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        res = [0] * (m * n)
        left, right, up, down = 0, n - 1, 0, m - 1
    
        index = 0
        direction = 0
        while left <= right and up <= down:
            if direction == 0:
                # Traverse right
                for col in range(left, right + 1):
                    res[index] = matrix[up][col]
                    index += 1
                up += 1
                direction = 1
            elif direction == 1:
                # Traverse down
                for row in range(up, down + 1):
                    res[index] = matrix[row][right]
                    index += 1
                right -= 1
                direction = 2
            elif direction == 2:
                # Traverse left
                for col in range(right, left - 1, -1):
                    res[index] = matrix[down][col]
                    index += 1
                down -= 1
                direction = 3
            else:
                # Traverse up
                for row in range(down, up - 1, -1):
                    res[index] = matrix[row][left]
                    index += 1
                left += 1
                direction = 0

        return res

