class Solution {
public:
    int N, M;
    vector<vector<int>> m_matrix, cache;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    bool IsValid(int r, int c, int cur){
        if(r < 0 || r >= N || c < 0 || c >= M)return false;
        return cur < m_matrix[r][c];
    }

    int DFS(int r, int c){
        int& ret = cache[r][c];
        if(ret != -1) return ret;
        ret = 0;

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(IsValid(nr, nc, m_matrix[r][c])){
                ret = max(ret, DFS(nr, nc)+1);
            }
        }
        return ret;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        N = matrix.size(), M = matrix[0].size(), m_matrix = matrix;
        cache.resize(N, vector<int>(M, -1));
        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j  < M; j++){
                ret = max(ret, DFS(i, j)+1);
            }
        }

        return ret;
    }
};