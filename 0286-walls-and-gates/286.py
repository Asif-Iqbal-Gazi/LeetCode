from collections import deque


class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Approach:
        1. Multi-Source BFS from Gates -- T.C: O(M*N),     S.C: O(M*N)
             - Enqueue all gates simultaneously, expand outward level by level.
               Each empty room is visited exactly once.
        """

        INF = 2147483647
        m, n = len(rooms), len(rooms[0])
        dq = deque()

        for r in range(m):
            for c in range(n):
                if rooms[r][c] == 0:
                    dq.append((r, c))

        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        while dq:
            r, c = dq.popleft()
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if nr < 0 or nr >= m or nc < 0 or nc >= n or rooms[nr][nc] != INF:
                    continue
                rooms[nr][nc] = rooms[r][c] + 1
                dq.append((nr, nc))
