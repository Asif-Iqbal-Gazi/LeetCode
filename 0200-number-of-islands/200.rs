use std::collections::VecDeque;

impl Solution {
    fn dfs(r: i32, c: i32, m: i32, n: i32, grid: &mut Vec<Vec<char>>) -> i32 {
        if r < 0 || r >= m || c < 0 || c >= n || grid[r as usize][c as usize] != '1' {
            return 0;
        }
        grid[r as usize][c as usize] = '2';
        let count = 1
            + Self::dfs(r, c + 1, m, n, grid)
            + Self::dfs(r + 1, c, m, n, grid)
            + Self::dfs(r, c - 1, m, n, grid)
            + Self::dfs(r - 1, c, m, n, grid);
        count
    }

    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        /*
         * Approach:
         * 1. DFS -- T.C: O(M * N), S.C: O(M * N)
         *      - When a '1' is found, increment count and sink the entire
         *        island via DFS by marking connected cells as '2'.
         * 2. BFS -- T.C: O(M * N), S.C: O(M * N)
         *      - Same logic as DFS but uses a queue for level-by-level traversal.
         */

        // Approach 2 -- BFS
        let m       = grid.len() as i32;
        let n       = grid[0].len() as i32;
        let mut islands = 0;
        let dirs: [(i32, i32); 4] = [(0, 1), (1, 0), (0, -1), (-1, 0)];
        for r in 0..m {
            for c in 0..n {
                if grid[r as usize][c as usize] != '1' {
                    continue;
                }
                islands += 1;
                grid[r as usize][c as usize] = '2';
                let mut dq = VecDeque::new();
                dq.push_back((r, c));
                while let Some((cr, cc)) = dq.pop_front() {
                    for (dr, dc) in dirs {
                        let nr = cr + dr;
                        let nc = cc + dc;
                        if nr < 0 || nr >= m || nc < 0 || nc >= n {
                            continue;
                        }
                        if grid[nr as usize][nc as usize] != '1' {
                            continue;
                        }
                        grid[nr as usize][nc as usize] = '2';
                        dq.push_back((nr, nc));
                    }
                }
            }
        }
        islands

        /* Approach 1 -- DFS
        let m           = grid.len() as i32;
        let n           = grid[0].len() as i32;
        let mut islands = 0;
        for r in 0..m {
            for c in 0..n {
                if grid[r as usize][c as usize] == '1' {
                    islands += 1;
                    Self::dfs(r, c, m, n, &mut grid);
                }
            }
        }
        islands
        */
    }
}
