class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        n, m = len(mat), len(mat[0])
        res = [0] * (n * m)
        
        row = col = 0
        for i in range(n * m):
            res[i] = mat[row][col]

            if (row + col) % 2 == 0:
                # Moving Up
                if col == m - 1:
                    row += 1
                elif row == 0:
                    col += 1
                else:
                    row -= 1
                    col += 1
            else:
                # Moving Down
                if row == n - 1:
                    col += 1
                elif col == 0:
                    row += 1
                else:
                    row += 1
                    col -= 1

        return res


        
