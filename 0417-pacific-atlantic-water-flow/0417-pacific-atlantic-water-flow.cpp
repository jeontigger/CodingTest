class Solution {
public:
    int N, M;
    inline bool IsValid(int r, int c, vector<vector<int>>& visited) {
        return !(r < 0 || r >= N || c < 0 || c >= M) && !visited[r][c];
    }

    vector<vector<int>> BFS(int r1, int c1, int r2, int c2,
                            vector<vector<int>>& heights) {
        vector<vector<int>> visited(N, vector<int>(M));
        queue<pair<int, int>> q;
        for (int i = 0; i < r1; i++) {
            q.push({i, c1});
            visited[i][c1] = true;
        }
        for (int i = 0; i < c2; i++) {
            q.push({r2, i});
            visited[r2][i] = true;
        }

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = cur.first + dr[i];
                int nc = cur.second + dc[i];

                if (IsValid(nr, nc, visited)) {
                    if (heights[cur.first][cur.second] <= heights[nr][nc]) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return visited;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        N = heights.size(), M = heights[0].size();
        auto visitedA = BFS(N, M - 1, N - 1, M, heights);
        auto visitedP = BFS(N, 0, 0, M, heights);

        vector<vector<int>> ret;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visitedA[i][j] && visitedP[i][j]) {
                    ret.push_back({i, j});
                }
            }
        }

        return ret;
    }
};