#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <set>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <list>

using namespace std;

#define INF 1e9

template<typename T>
void PrintVec(const vector<T>& v) {
	for (T i : v) {
		cout << i << " ";
	}
	cout << '\n';
}

template<typename T>
void PrintVec(const vector<vector<T>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

// 상하좌우로 기울여서 빨간 구슬을 구멍에 넣지만 파란 구슬은 넣으면 안되는 게임
// 10 회 이내로 실패한다면 -1을 리턴한다
// DFS에서 10회를 넘어가면 -1, 호출하는 부분에선 res가 -1이 아닐때 최소값 갱신, -1 때는 계속 갱신


// 빈칸일 경우 계속 이동
// 기울이는 쪽에 가까운 구슬을 찾아서 먼저 움직임. 빨, 파, 빨, 파 순으로 하면 상관은 없어보이긴 함

int N, M;
vector<string> map;
int r_r, r_c, b_r, b_c;

void Inputs() {
	cin >> N >> M;
	map.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> map[i];

		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				r_r = i;
				r_c = j;
			}
			else if (map[i][j] == 'B') {
				b_r = i;
				b_c = j;
			}
		}
	}
}

struct Step {
	int rr, rc, br, bc, cnt;
};

int nrow[4] = { 0, 1, 0, -1 };
int ncol[4] = { 1, 0, -1, 0 };
int Move(int& _row, int& _col, int dir) {

	int res = 0;
	while (map[_row + nrow[dir]][_col + ncol[dir]] != '#' && map[_row][_col] != 'O') {
		_row += nrow[dir];
		_col += ncol[dir];
		res++;
	}

	return res;
}

void BFS() {
	queue<Step> q;
	bool visited[11][11][11][11] = { false, };
	visited[r_r][r_c][b_r][b_c] = true;
	q.push({ r_r, r_c, b_r, b_c, 0 });

	while (!q.empty()) {
		Step step = q.front();
		q.pop();

		if (step.cnt >= 10) break;

		for (int i = 0; i < 4; i++) {
			int rr = step.rr, rc = step.rc, br = step.br, bc = step.bc;

			int rd = Move(rr, rc, i);
			int bd = Move(br, bc, i);

			if (map[br][bc] == 'O') continue;
			if (map[rr][rc] == 'O') {
				cout << step.cnt + 1;
				return;
			}

			if (rr == br && rc == bc) {
				if (rd > bd) {
					rr -= nrow[i];
					rc -= ncol[i];
				}
				else {
					br -= nrow[i];
					bc -= ncol[i];
				}
			}

			if (!visited[rr][rc][br][bc]) {
				q.push({ rr, rc, br, bc, step.cnt + 1 });
				visited[rr][rc][br][bc] = true;
			}
		}
	}
	cout << -1;
}

void Solution() {
	BFS();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 1;
	//cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}