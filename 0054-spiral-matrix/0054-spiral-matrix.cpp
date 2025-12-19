class Solution {
public:
    enum EDir{RIGHT, DOWN, LEFT, UP};
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    int N, M;
    vector<vector<int>>visited;

    inline bool Boundary(int r, int c){
        return !(r < 0 || r >= N || c < 0 || c >= M);
    }

    inline bool IsValid(int r, int c){
        return Boundary(r, c) && !visited[r][c];
    }

    struct Pos{
        int r = 0, c = 0;
    };

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        N = matrix.size(), M = matrix[0].size();
        int cnt = N * M - 1;
        Pos cur = {0, 0};
        EDir dir = RIGHT;
        visited.resize(N, vector<int>(M));
        vector<int> ret;
        visited[0][0] = true;
        ret.push_back(matrix[0][0]);
        while(cnt != 0){
            int nr = cur.r + dr[dir];
            int nc = cur.c + dc[dir];
            
            if(!IsValid(nr, nc)){
                dir = EDir((dir + 1) % 4);
            }else{
                // cout << nr << ' ' << nc << '\n';
                visited[nr][nc] = true;
                cur = {nr, nc};
                cnt--;
                ret.push_back(matrix[nr][nc]);
            }
        }
        return ret;
    }
};