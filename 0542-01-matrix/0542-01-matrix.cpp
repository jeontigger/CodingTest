class Solution {
public:
    vector<vector<int>> m_mat;
    vector<vector<int>> m_visited;
    int N, M;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    bool IsValid(int r, int c) {
        return !(r < 0 || r >= N || c < 0 || c >= M) && !m_visited[r][c] &&
               m_mat[r][c] == 1;
    }

    void BFS() {
        queue<pair<int, int>> q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (m_mat[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int time = 0;
        while (!q.empty()) {
            time++;
            int size = q.size();
            while (size--) {
                auto pos = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = pos.first + dr[i];
                    int nc = pos.second + dc[i];

                    if (IsValid(nr, nc)) {
                        m_visited[nr][nc] = true;
                        m_mat[nr][nc] = time;

                        // cout << nr << ' ' << nc << ' ' << time << '\n';
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m_mat = mat;
        N = mat.size(), M = mat[0].size();
        m_visited.resize(N, vector<int>(M));
        BFS();
        return m_mat;
    }
};