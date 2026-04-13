class Solution:
    def dfs(self, r: int, c: int, m: int, n: int, grid: List[List[str]]) -> int:
        if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] != "1":
            return 0
        grid[r][c] = "2"
        count = 1

        count += self.dfs(r, c + 1, m, n, grid)
        count += self.dfs(r + 1, c, m, n, grid)
        count += self.dfs(r, c - 1, m, n, grid)
        count += self.dfs(r - 1, c, m, n, grid)
        return count

    def numIslands(self, grid: List[List[str]]) -> int:
        # Approach:
        # 1. DFS -- T.C: O(M * N), S.C: O(M * N)
        #      - When a '1' is found, increment count and sink the entire
        #        island via DFS by marking connected cells as '0'.
        # 2. BFS -- T.C: O(M * N), S.C: O(M * N)
        #      - Same logic as DFS but uses a queue for level-by-level traversal.

        # Approach 2 - BFS
        m, n = len(grid), len(grid[0])
        islands = 0

        dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    islands += 1
                    grid[i][j] = "2"
                    dq = deque([(i, j)])
                    while dq:
                        r, c = dq.popleft()
                        for dr, dc in dirs:
                            nr, nc = r + dr, c + dc
                            if (
                                nr < 0
                                or nr >= m
                                or nc < 0
                                or nc >= n
                                or grid[nr][nc] != "1"
                            ):
                                continue
                            grid[nr][nc] = "2"
                            dq.append((nr, nc))

        return islands

        ## Approach 1 - DFS
        # m, n = len(grid), len(grid[0])
        # islands = 0

        # for r in range(m):
        #     for c in range(n):
        #         if grid[r][c] == "1":
        #             islands += 1
        #             self.dfs(r, c, m, n, grid)

        # return islands
