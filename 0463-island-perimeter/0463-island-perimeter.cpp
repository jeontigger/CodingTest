class Solution {
public:
    int N, M;
    vector<vector<int>> m_grid;
    vector<vector<int>> m_visited;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    bool IsValid(int r, int c) {
        if (r < 0 || r >= N || c < 0 || c >= M)
            return false;
        return !m_visited[r][c] && !m_grid[r][c];
    }
    bool IsLand(int r, int c) {
        if (r < 0 || r >= N || c < 0 || c >= M)
            return false;
        return m_grid[r][c];
    }

    int DFS(int r, int c) {
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (IsValid(nr, nc)) {
                m_visited[nr][nc] = 1;
                ret+=DFS(nr, nc);
            }else if(IsLand(nr, nc)){
                ret++;
            }
        }

        return ret;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        // 벽에 닿은 개수 + 바다에 닿은 섬 개수?
        N = grid.size(), M = grid[0].size();
        m_grid = grid;
        m_visited.resize(N, vector<int>(M));

        int ret = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (IsValid(i, j)) {
                    m_visited[i][j] = true;
                    ret += DFS(i, j);
                }
            }
        }

        for(int i = 0 ; i < N; i++){
            if(m_grid[i][0] == 1) ret++;
            if(m_grid[i][M-1] == 1) ret++;
        }

        for(int j = 0 ; j < M; j++){
            if(m_grid[0][j]) ret++;
            if(m_grid[N-1][j])ret++;
        }

        return ret;
    }
};