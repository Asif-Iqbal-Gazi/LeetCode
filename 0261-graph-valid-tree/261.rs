impl Solution {
    fn find(parent: &mut Vec<usize>, x: usize) -> usize {
        if parent[x] != x {
            parent[x] = Self::find(parent, parent[x]); // path compression
        }
        parent[x]
    }

    fn unite(parent: &mut Vec<usize>, rank: &mut Vec<usize>, x: usize, y: usize) -> bool {
        let px = Self::find(parent, x);
        let py = Self::find(parent, y);
        if px == py {
            return false; // cycle detected
        }
        // union by rank
        if      rank[px] < rank[py] { parent[px] = py; }
        else if rank[px] > rank[py] { parent[py] = px; }
        else                        { parent[py] = px; rank[px] += 1; }
        true
    }

    pub fn valid_tree(n: i32, edges: Vec<Vec<i32>>) -> bool {
        /*
         * Approach:
         * 1. DFS        -- T.C: O(V + E),    S.C: O(V + E)
         *      - Build adjacency list, run DFS tracking visited and parent.
         *        Cycle = visited non-parent node. Check all visited for connectivity.
         * 2. BFS        -- T.C: O(V + E),    S.C: O(V + E)
         *      - Same as DFS but level by level using a queue.
         * 3. Union Find -- T.C: O(E · α(V)), S.C: O(V)
         *      - For each edge, if both nodes share a root → cycle.
         *        After all edges, verify exactly n - 1 edges exist.
         */

        // Approach 3 -- Union Find
        let n = n as usize;
        if edges.len() != n - 1 {
            return false;
        }
        let mut parent: Vec<usize> = (0..n).collect();
        let mut rank               = vec![0usize; n];
        for edge in &edges {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            if !Self::unite(&mut parent, &mut rank, u, v) {
                return false;
            }
        }
        true

        /* Approach 1 -- DFS
        let n = n as usize;
        if edges.len() != n - 1 { return false; }
        let mut adj     = vec![vec![]; n];
        for edge in &edges {
            let (u, v) = (edge[0] as usize, edge[1] as usize);
            adj[u].push(v);
            adj[v].push(u);
        }
        let mut visited = vec![false; n];
        let mut stack   = vec![(0usize, usize::MAX)]; // (node, parent)
        while let Some((node, par)) = stack.pop() {
            visited[node] = true;
            for &neighbor in &adj[node] {
                if !visited[neighbor] {
                    stack.push((neighbor, node));
                } else if neighbor != par {
                    return false;
                }
            }
        }
        visited.iter().all(|&v| v)
        */

        /* Approach 2 -- BFS
        use std::collections::VecDeque;
        let n = n as usize;
        if edges.len() != n - 1 { return false; }
        let mut adj     = vec![vec![]; n];
        for edge in &edges {
            let (u, v) = (edge[0] as usize, edge[1] as usize);
            adj[u].push(v);
            adj[v].push(u);
        }
        let mut visited = vec![false; n];
        let mut dq      = VecDeque::new();
        dq.push_back((0usize, usize::MAX)); // (node, parent)
        while let Some((node, par)) = dq.pop_front() {
            visited[node] = true;
            for &neighbor in &adj[node] {
                if !visited[neighbor] {
                    dq.push_back((neighbor, node));
                } else if neighbor != par {
                    return false;
                }
            }
        }
        visited.iter().all(|&v| v)
        */
    }
}
