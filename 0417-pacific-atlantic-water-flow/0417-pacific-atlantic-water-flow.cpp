class Solution {
public:
    vector<vector<int>> visited, m_heights, cnts, ret;
    int N, M;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    bool IsValid(int r, int c, int cur) {
        if (r < 0 || r >= N || c < 0 || c >= M)
            return false;

        return !visited[r][c] && cur <= m_heights[r][c];
    }

    void DFS(int r, int c) {
        cnts[r][c]++;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (IsValid(nr, nc, m_heights[r][c])) {
                visited[nr][nc] = true;
                DFS(nr, nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m_heights = heights;
        N = m_heights.size(), M = m_heights[0].size();

        visited.resize(N, vector<int>(M));
        cnts.resize(N, vector<int>(M));

        for(int i = 0 ; i < N; i++){
            if(!visited[i][M-1]){
                visited[i][M-1] = true;
                DFS(i, M-1);
            }
        }
        for(int i = 0; i < M; i++){
            if(!visited[N-1][i]){
                visited[N-1][i] = true;
                DFS(N-1, i);
            }
        }

        visited.assign(N, vector<int>(M));

        for(int i = 0 ; i < N; i++){
            if(!visited[i][0]){
                visited[i][0] = true;
                DFS(i, 0);
            }
        }
        for(int i = 0; i < M; i++){
            if(!visited[0][i]){
                visited[0][i] = true;
                DFS(0, i);
            }
        }

        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < M; j++){
                if(cnts[i][j] == 2) ret.push_back({i, j});
                // cout << cnts[i][j] << ' ';
            }
            // cout << '\n';
        }

        return ret;
    }
};