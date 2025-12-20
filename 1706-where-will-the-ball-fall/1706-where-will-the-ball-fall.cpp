class Solution {
public:
    int N, M;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    vector<vector<int>> m_grid;
    inline bool Boundary(int r, int c){
        return !(r < 0 || r >= N || c < 0 || c >= M);
    }

    inline bool CanFall(int r, int c){
        int nc = c;
        if(m_grid[r][c] == 1){
            nc++;
        }else{
            nc--;
        }
        return Boundary(r, nc) && m_grid[r][c] == m_grid[r][nc];
    }

    struct Pos{
        int r = 0, c = 0;
    };

    inline Pos Next(int r, int c){
        // cout << r << ' ' << c << ' ' << m_grid[r][c] << '\n';
        if(m_grid[r][c] == 1){
            c++;
        }else{
            c--;
        }
        r++;
        return {r, c};
    }

    vector<vector<int>> cache;

    int Fall(int r, int c){
        // cout << r << ' ' << c << '\n';
        int& ret = cache[r][c];
        if(ret != -2)return ret;

        if(r == N-1){
            if(CanFall(r, c)){
                auto pos = Next(r, c);
                return ret = pos.c;
            }else{
                return ret = -1;
            }
                
        }

        ret = -1;
        if(CanFall(r, c)){
        // cout << r << ' ' << c << '\n';
            auto next = Next(r, c);
            // cout << next.r << ' '<< next.c << '\n';
            ret = Fall(next.r, next.c);
        }

        return ret;
        
    }


    vector<int> findBall(vector<vector<int>>& grid) {
        // 떨어진 공은 같은행 다음 방향 열이 같은 방향이라면 다음 열, 다음 행으로 떨어질 수 있음
        // 같은 행 다음 방향 열이 바깥이거나, 나와 반대 방향이라면 그대로 갖힘
        // 빠르게 해야하니까 지나온 곳은 cahche 사용하기

        // 그럼 같은 행 다음 열이 나와 같은 방향인지 체크하는 함수
        // 다음 행 다음 열을 받아오는 함수
        
        N = grid.size(), M = grid[0].size();
        m_grid = grid;
        cache.resize(N, vector<int>(M, -2));

        vector<int> ret;
        for(int i = 0; i < M; i++){
            // Fall(0, i) ? ret.push_back(1) : ret.push_back(-1);
            ret.push_back(Fall(0, i));
        }

        return ret;
    }
};