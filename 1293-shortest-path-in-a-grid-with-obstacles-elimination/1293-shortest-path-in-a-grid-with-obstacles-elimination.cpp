class Solution {
public:
    int N, M;
    struct Node {
        int r, c, b;
    };

    inline bool Boundary(int r, int c) {
        return !(r < 0 || r >= N || c < 0 || c >= M);
    }

    inline bool IsWall(int r, int c, vector<vector<int>>& grid) {
        return grid[r][c] == 1;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        // 1개의 벽을 부술 수 있는 문제에 가까운듯
        N = grid.size(), M = grid[0].size();
        // [break][r][c]
        vector<vector<vector<int>>> visited(
            k+1, vector<vector<int>>(N, vector<int>(M)));

        // 0, 0부터 N-1, M-1까지
        queue<Node> q;
        q.push({0, 0, 0});
        visited[0][0][0] = true;

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        int cnt = -1;
        while (!q.empty()) {
            int size = q.size();
            cnt++;
            while (size--) {
                auto cur = q.front();
                q.pop();

                if (cur.r == N - 1 && cur.c == M - 1) {
                    return cnt;
                }

                for (int i = 0; i < 4; i++) {
                    int nr = cur.r + dr[i];
                    int nc = cur.c + dc[i];
                    if (Boundary(nr, nc)) {
                        int nb = cur.b + IsWall(nr, nc, grid);
                        if (nb > k)
                            continue;
                        if (!visited[nb][nr][nc]) {
                            visited[nb][nr][nc] = true;
                            q.push({nr, nc, nb});
                        }
                    }
                }
            }
        }
        return -1;
    }
};