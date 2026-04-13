use std::collections::VecDeque;

impl Solution {
    pub fn walls_and_gates(rooms: &mut Vec<Vec<i32>>) {
        /*
         * Approach:
         * 1. Multi-Source BFS from Gates -- T.C: O(M*N),     S.C: O(M*N)
         *      - Enqueue all gates simultaneously, expand outward level by level.
         *        Each empty room is visited exactly once.
         */

        const INF: i32 = 2147483647;
        let m = rooms.len();
        let n = rooms[0].len();
        let mut dq = VecDeque::new();

        for r in 0..m {
            for c in 0..n {
                if rooms[r][c] == 0 {
                    dq.push_back((r, c));
                }
            }
        }

        let dirs: [(i32, i32); 4] = [(0,1), (1,0), (0, -1), (-1, 0)];
        while let Some((r, c)) = dq.pop_front() {
            for (dr, dc) in dirs {
                let nr = r as i32 + dr;
                let nc = c as i32 + dc;
                if nr < 0 || nr >= m as i32 || nc < 0 || nc >= n as i32 {
                    continue;
                }
                let (nr, nc) = (nr as usize, nc as usize);
                if rooms[nr][nc] != INF {
                    continue;
                }
                rooms[nr][nc] = rooms[r][c] + 1;
                dq.push_back((nr, nc));
            }

        }
    }
}
