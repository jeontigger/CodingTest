class Solution {
public:
int N, M;
vector<vector<int>>visited;
vector<vector<char>> ret;
vector<vector<char>> m_board;
    inline bool IsValid(int r, int c){
        return !(r < 0 || r >= N || c < 0 || c>= M) && !visited[r][c] && m_board[r][c] == 'O';
    }
    void BFS(int r, int c){
        queue<pair<int, int>> q;
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        q.push({r, c});
        visited[r][c] = true;
        ret[r][c] = 'O';

        while(!q.empty()){
            auto pos = q.front();
            q.pop();

            for(int i = 0 ; i < 4; i++){
                int nr = pos.first + dr[i];
                int nc = pos.second + dc[i];

                if(IsValid(nr, nc)){
                    visited[nr][nc] =true;
                    ret[nr][nc] = 'O';
                    q.push({nr, nc});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        N = board.size(), M = board[0].size();
        m_board = board;
        ret.resize(N, vector<char>(M, 'X'));
        visited.resize(N, vector<int>(M));

        for(int r = 0 ; r < N; r++){
            if(IsValid(r, 0)){
                BFS(r, 0);
            }
            if(IsValid(r, M-1)){
                BFS(r, M-1);
            }
        }

        for(int c = 0 ; c < M; c++){
            if(IsValid(0, c)){
                BFS(0, c);
            }
            if(IsValid(N-1, c)){
                BFS(N-1, c);
            }
        }
        swap(board, ret);
    }
};