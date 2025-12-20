class Solution {
public:
    struct Pos {
        int r = 0, c = 0;
    };
    enum EDir {DOWN, UR, END};
    int dr[END] = {1, -1};
    int dc[END] = {0, 1};
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        // matrix를 만들어서 설계? -> x
        // pos를 설계
        Pos cur = {-1, 0};
        EDir dir =  DOWN;
        vector<Pos> path(s.size());
        int M = 0;
        for(int i = 0; i < s.size(); i++){
            Pos next = cur;
            next.r += dr[dir];
            next.c += dc[dir];
            M = next.c;
            if(next.r == 0) dir = DOWN;
            if(next.r == numRows-1) dir = UR;
            path[i] = next;
            cur = next;
        }

        vector<vector<char>>matrix(numRows, vector<char>(M+1));
        for(int i = 0 ; i < path.size(); i++){
            Pos pos = path[i];
            matrix[pos.r][pos.c] = s[i];
        }

        string ret = "";
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0 ; j < matrix[0].size(); j++){
                if(matrix[i][j] != 0){
                    ret += matrix[i][j];
                }
            }
        }

        return ret;
    }
};