class Solution {
public:
    int N, M;
    vector<vector<char>> m_board;
    vector<vector<int>> visited;
    string m_word;

    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    
    bool IsValid(int r, int c, int idx) {
        if (r < 0 || r >= N || c < 0 || c >= M)
            return false;
        return !visited[r][c] && m_word[idx] == m_board[r][c];
    }

    bool DFS(int r, int c, int idx){
        if(idx == m_word.size()-1) return true;
        // cout << r << ' ' << c << ' ' << idx << '\n';
        for(int i = 0 ; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(IsValid(nr, nc, idx + 1)){
                visited[nr][nc] = true;
                if(DFS(nr, nc, idx+1))return true;
                visited[nr][nc] = false;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        N = board.size(), M = board[0].size();
        m_board = board;
        m_word = word;
        visited.resize(N, vector<int>(M));
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (IsValid(r, c, 0)){
                    visited[r][c] = true;
                    // cout << r << ' ' << c << ' ' << m_board[r][c] << '\n';
                    if(DFS(r, c, 0)) return true;
                    cout << '\n';
                    visited[r][c] = false;
                }
            }
        }
        return false;
    }
};