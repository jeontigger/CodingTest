class Solution {
public:
    int N, M;
    vector<vector<int>> visited;
    vector<vector<char>> m_board;
    vector<vector<char>> g_board;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    bool IsValid(int r, int c) {
        if (r < 0 || r >= N || c < 0 || c >= M)
            return false;
        return !visited[r][c] && g_board[r][c] == 'O';
    }

    void DFS(int r, int c) {
        visited[r][c] = true;
        m_board[r][c] = 'O';

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (IsValid(nr, nc)) {
                DFS(nr, nc);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        N = board.size(), M = board[0].size();
        visited.resize(N, vector<int>(M));
        m_board.resize(N, vector<char>(M, 'X'));
        g_board = board;

        for (int c = 0; c < M; c++) {
            if (IsValid(0, c)) {
                DFS(0, c);
            }
            if (IsValid(N - 1, c)) {
                DFS(N - 1, c);
            }
        }

        for (int r = 0; r < N; r++) {
            if (IsValid(r, 0)) {
                DFS(r, 0);
            }
            if (IsValid(r, M-1)) {
                DFS(r, M-1);
            }
        }
        swap(m_board, board);
    }
};