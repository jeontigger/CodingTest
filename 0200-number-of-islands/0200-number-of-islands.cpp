class Solution {
public:
    vector<vector<char>> m_grid;
    int N, M;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    bool IsValid(int r, int c) {
        return !(r < 0 || r >= N || c < 0 || c >= M) && m_grid[r][c] == '1';
    }

    int BFS(int r, int c) {
        m_grid[r][c] = '0';
        queue<pair<int, int>> q;
        q.push({r, c});

        int ret = 0;
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();

            ret++;
            for (int i = 0; i < 4; i++) {
                int nr = pos.first + dr[i];
                int nc = pos.second + dc[i];

                if (IsValid(nr, nc)) {
                    m_grid[nr][nc] = '0';
                    q.push({nr, nc});
                }
            }
        }

        return ret;
    }
    int numIslands(vector<vector<char>>& grid) {
        m_grid = grid;
        N = grid.size(), M = grid[0].size();

        int ret = 0;
        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < M; j++){
                if(IsValid(i, j)){
                    BFS(i, j);
                    ret++;
                }
            }
        }
        return ret;
    }
};