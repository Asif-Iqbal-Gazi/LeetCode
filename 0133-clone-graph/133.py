"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        """
        Approach:
        1. DFS + Hash Map -- T.C: O(V + E), S.C: O(V)
             - Recursively clone each node. Use a hash map to track already
               cloned nodes to avoid infinite loops in cyclic graphs.
        2. BFS + Hash Map -- T.C: O(V + E), S.C: O(V)
             - Clone nodes level by level using a queue.
        """

        # Approach 2 -- BFS
        if not node:
            return None
        from collections import deque

        clone_map = {}
        clone_map[node] = Node(node.val)

        dq = deque([node])

        while dq:
            curr_node = dq.popleft()
            for neighbor in curr_node.neighbors:
                if neighbor not in clone_map:
                    clone_map[neighbor] = Node(neighbor.val)
                    dq.append(neighbor)
                clone_map[curr].neighbors.append(clone_map[neighbor])
        return clone_map[node]

        ## Approach 1 -- DFS
        # clone_map = {}

        # def dfs(node: Optional["Node"]) -> Optional["Node"]:
        #    if not node:
        #        return None

        #    if node in clone_map:
        #        return clone_map[node]
        #    curr_clone = Node(node.val)
        #    clone_map[node] = curr_clone

        #    for neighbor in node.neighbors:
        #        curr_clone.neighbors.append(dfs(neighbor))
        #    return curr_clone

        # return dfs(node)
