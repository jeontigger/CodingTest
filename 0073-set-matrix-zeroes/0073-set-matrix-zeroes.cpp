class Solution {
public:
    int N, M;
    int nr[4] = {0, 1, 0, -1};
    int nc[4] = {1, 0, -1, 0};
    inline bool Boundary(int r, int c){
        return !(r < 0|| r >= N || c < 0 || c >= M);
    }

    struct Pos{
        int r = 0, c = 0;
    };

    void Bomb(Pos pos, vector<vector<int>>& matrix){
        for(int i = 0; i < N; i++){
            matrix[i][pos.c] = 0;
        }
        for(int i = 0; i < M; i++){
            matrix[pos.r][i] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        N = matrix.size(), M = matrix[0].size();
        vector<Pos> zeroPoses;
        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < M; j++){
                if(matrix[i][j] == 0){
                    zeroPoses.push_back({i, j});
                }
            }
        }

        for(int i = 0; i < zeroPoses.size(); i++){
            Bomb(zeroPoses[i], matrix);
        }
    }
};