class Solution {
public:
    // 스타팅 포인트가 주어지고
    // 소문자가 열쇠, 대문자가 잠긴 문
    // 모든 열쇠를 얻기까지 걸리는 최소 움직임 구하기
    // 못구하면 -1 리턴
    int N, M, target;

    struct Data {
        int r;
        int c;
        int k;
    };

    unordered_map<char, int> keyIdx;
    queue<Data> q;
    vector<vector<vector<int>>> visited;

    void Init(vector<string>& grid) {
        // N, M 갱신하기
        N = grid.size(), M = grid[0].size();

        // 열쇠 인덱싱하기
        // 시작 위치 찾기
        Data startPos;
        startPos.k = 0;
        int idx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '@') {
                    startPos.r = i;
                    startPos.c = j;
                } else if (islower(grid[i][j])) {
                    keyIdx[grid[i][j]] = idx++;
                } else if (isupper(grid[i][j])) {
                    // cout << grid[i][j] << ' ';
                }
            }
        }

        // 시작위치 Q에 넣기
        q.push(startPos);

        // visited 갱신하기 [key][row][col]
        target = pow(2, idx) - 1;
        // cout << target;
        visited.resize(target + 1, vector<vector<int>>(N, vector<int>(M)));
    }

    inline bool IsKey(int r, int c, vector<string>& grid) {
        return islower(grid[r][c]);
    }

    inline bool IsDoor(int r, int c, vector<string>& grid){
        return isupper(grid[r][c]);
    }

    inline bool CanUnlock(int r, int c, int k, char d){
        int idx = keyIdx[d + 'a' - 'A'];
        return k & (1 << idx);
    }

    inline bool IsValid(int r, int c, vector<string>& grid) {
        return !(r < 0 || r >= N || c < 0 || c >= M) && grid[r][c] != '#';
    }

    int shortestPathAllKeys(vector<string>& grid) {

        Init(grid);

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        int cnt = -1;
        while (!q.empty()) {
            cnt++;
            int size = q.size();
            while (size--) {
                auto pos = q.front();
                q.pop();

                if (pos.k == target) {
                    return cnt;
                }

                for (int i = 0; i < 4; i++) {
                    int nr = pos.r + dr[i];
                    int nc = pos.c + dc[i];
                    int nk = pos.k;
                    if (IsValid(nr, nc, grid)) {
                        if (IsKey(nr, nc, grid)) {
                            // cout << keyIdx[grid[nr][nc]] << ' ';
                            nk = nk | (1 << keyIdx[grid[nr][nc]]);
                        }

                        if(IsDoor(nr, nc, grid)){
                            if(!CanUnlock(nr, nc, nk, grid[nr][nc]))
                            continue;
                        }
                        // cout << nr << ' ' << nc << '\n';
                        if (!visited[nk][nr][nc]) {
                            visited[nk][nr][nc] = true;
                            q.push({nr, nc, nk});
                        }
                    }
                }
            }
        }

        return -1;
    }
};