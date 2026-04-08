# Python
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        """
        Approach:
        1. DFS        -- T.C: O(V + E),    S.C: O(V + E)
             - Build adjacency list, run DFS tracking visited and parent.
               Cycle = visited non-parent node. Check all visited for connectivity.
        2. BFS        -- T.C: O(V + E),    S.C: O(V + E)
             - Same as DFS but level by level using a queue.
        3. Union Find -- T.C: O(E · α(V)), S.C: O(V)
             - For each edge, if both nodes share a root → cycle.
               After all edges, verify exactly n - 1 edges exist.
        """

        # Approach 3 -- Union Find
        if len(edges) != n - 1:
            return False

        parent = list(range(n))
        rank = [0] * n

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])  # path compression
            return parent[x]

        def unite(x, y):
            px, py = find(x), find(y)
            if px == py:
                return False  # cycle detected
            if rank[px] < rank[py]:
                parent[px] = py
            elif rank[px] > rank[py]:
                parent[py] = px
            else:
                parent[py] = px
                rank[px] += 1
            return True

        return all(unite(u, v) for u, v in edges)

        # Approach 1 -- DFS
        # if len(edges) != n - 1:
        #     return False
        # adj     = [[] for _ in range(n)]
        # for u, v in edges:
        #     adj[u].append(v)
        #     adj[v].append(u)
        # visited = [False] * n
        # stack   = [(0, -1)]  # (node, parent)
        # while stack:
        #     node, par = stack.pop()
        #     visited[node] = True
        #     for neighbor in adj[node]:
        #         if not visited[neighbor]:
        #             stack.append((neighbor, node))
        #         elif neighbor != par:
        #             return False
        # return all(visited)

        # Approach 2 -- BFS
        # from collections import deque
        # if len(edges) != n - 1:
        #     return False
        # adj     = [[] for _ in range(n)]
        # for u, v in edges:
        #     adj[u].append(v)
        #     adj[v].append(u)
        # visited = [False] * n
        # dq      = deque([(0, -1)])  # (node, parent)
        # while dq:
        #     node, par = dq.popleft()
        #     visited[node] = True
        #     for neighbor in adj[node]:
        #         if not visited[neighbor]:
        #             dq.append((neighbor, node))
        #         elif neighbor != par:
        #             return False
        # return all(visited)
