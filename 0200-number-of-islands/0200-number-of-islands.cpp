class Solution {
public:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    int N, M;
    vector<vector<char>> m_grid;
    bool IsValid(int r, int c){
        if(r < 0 || r >= N || c < 0 || c >= M)return false;
        return m_grid[r][c] == '1';
    }

    int DFS(int r, int c) {
        int ret = 1;

        for(int i = 0 ; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(IsValid(nr, nc)){
                m_grid[nr][nc] = '0';
                ret += DFS(nr, nc);
            }
        }

        return ret;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        m_grid = grid;
        N = grid.size(), M = grid[0].size();

        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < M; j++){
                if(IsValid(i, j)){
                    m_grid[i][j] = '0';
                    DFS(i, j);
                    ret++;
                }
            }
        }

        return ret;
    }
};