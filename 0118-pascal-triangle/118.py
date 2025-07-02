class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = []

        for row in range(numRows):
            curr = [1] * (row + 1)
            for col in range(1, row):
                curr[col] = triangle[row - 1][col - 1] + triangle[row - 1][col]
            triangle.append(curr)

        return triangle
