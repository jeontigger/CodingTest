#include <bits/stdc++.h>
using namespace std;

#define FOR(idx, limit) for (int idx = 0; idx < limit; idx++)

int maps[9][9];

// row[r][n] : r행에 숫자 n이 이미 있는가?
// col[c][n] : c열에 숫자 n이 이미 있는가?
// box[b][n] : b번째 3x3 박스에 숫자 n이 이미 있는가?
bool rowUsed[9][10];
bool colUsed[9][10];
bool boxUsed[9][10];

vector<pair<int,int>> blanks; // 0인 칸들의 위치 저장

bool Inputs() {
    FOR(i, 9) {
        FOR(j, 9) {
            char c;
            if (!(cin >> c)) return false;
            maps[i][j] = c - '0';
        }
    }
    return true;
}

inline int GetBoxIndex(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

bool DFS(int idx) {
    // 모든 빈 칸을 다 채웠으면 성공
    if (idx == (int)blanks.size()) return true;

    int r = blanks[idx].first;
    int c = blanks[idx].second;
    int b = GetBoxIndex(r, c);

    // 1 ~ 9까지 시도
    for (int num = 1; num <= 9; num++) {
        if (rowUsed[r][num]) continue;
        if (colUsed[c][num]) continue;
        if (boxUsed[b][num]) continue;

        // 이 숫자 사용
        maps[r][c] = num;
        rowUsed[r][num] = colUsed[c][num] = boxUsed[b][num] = true;

        if (DFS(idx + 1)) return true;

        // 백트래킹 (되돌리기)
        maps[r][c] = 0;
        rowUsed[r][num] = colUsed[c][num] = boxUsed[b][num] = false;
    }

    return false; // 이 칸에서 어떤 숫자도 넣을 수 없음 → 실패
}

void Solution() {
    // rowUsed / colUsed / boxUsed 초기 세팅
    memset(rowUsed, 0, sizeof(rowUsed));
    memset(colUsed, 0, sizeof(colUsed));
    memset(boxUsed, 0, sizeof(boxUsed));
    blanks.clear();

    FOR(i, 9) {
        FOR(j, 9) {
            int val = maps[i][j];
            if (val == 0) {
                blanks.push_back({i, j});
            } else {
                int b = GetBoxIndex(i, j);
                rowUsed[i][val] = true;
                colUsed[j][val] = true;
                boxUsed[b][val] = true;
            }
        }
    }

    DFS(0);

    // 출력
    FOR(i, 9) {
        FOR(j, 9) {
            cout << maps[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    // cin >> T; // 2239는 항상 1개
    while (T--) {
        if (!Inputs()) break;
        Solution();
    }
    return 0;
}
