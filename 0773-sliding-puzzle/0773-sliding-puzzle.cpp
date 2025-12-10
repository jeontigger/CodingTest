class Solution {
public:
    inline int Encode(const vector<vector<int>>& board) {
        int ret = 0;
        ret += board[0][0];
        ret += board[0][1] * 6;
        ret += board[0][2] * 6 * 6;
        ret += board[1][0] * pow(6, 3);
        ret += board[1][1] * pow(6, 4);
        ret += board[1][2] * pow(6, 5);
        return ret;
    }

    inline vector<vector<int>> Decode(int num) {
        vector<vector<int>> ret(2, vector<int>(3));
        ret[0][0] = num % 6;
        num /= 6; // a0
        ret[0][1] = num % 6;
        num /= 6; // a1
        ret[0][2] = num % 6;
        num /= 6; // a2
        ret[1][0] = num % 6;
        num /= 6; // a3
        ret[1][1] = num % 6;
        num /= 6;            // a4
        ret[1][2] = num % 6; // a5
        return ret;
    }

    inline bool Boundary(int r, int c) {
        return !(r < 0 || r >= 2 || c < 0 || c >= 3);
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        int target = 7465;

        // 6^6 + 1만큼 할당
        vector<int> visited(46657);
        int start = Encode(board);
        visited[start] = true;
        queue<int> q;
        q.push(start);
        // cout << start << '\n';

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        int turn = -1;
        while (!q.empty()) {
            turn++;
            int size = q.size();
            while (size--) {
                int cur = q.front();
                q.pop();

                if (cur == target)
                    return turn;

                auto vec = Decode(cur);
                int zr = -1, zc = -1;
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (vec[i][j] == 0) {
                            zr = i;
                            zc = j;
                            break;
                        }
                    }
                    if (zr != -1)
                        break;
                }

                for (int i = 0; i < 4; i++) {
                    int nr = zr + dr[i];
                    int nc = zc + dc[i];
                    if (Boundary(nr, nc)) {
                        swap(vec[zr][zc], vec[nr][nc]);
                        int next = Encode(vec);
                        if (!visited[next]) {
                            visited[next] = true;
                            q.push(next);
                        }
                        swap(vec[zr][zc], vec[nr][nc]);
                    }
                }
            }
        }

        return -1;
    }
};