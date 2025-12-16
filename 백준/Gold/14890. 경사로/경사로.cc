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
#include <map>

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
#define FOR(idx, limit) for(int idx = 0; idx < limit; idx++)

int N, L;
int maps[100][100];

enum EDir { UP, RIGHT, DOWN, LEFT };
int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };

bool Inputs() {
	cin >> N >> L;
	FOR(r, N)
		FOR(c, N)
		cin >> maps[r][c];

	return true;
}

// 아예 경사로로 커버가 안되는지
// 경사로가 필요한지
// 경사로를 놓을 수 있는지

bool CanCandidate(int idx, char type) {
	if (type == 'v') {
		for (int i = 0; i < N - 1; i++) {
			if (abs(maps[i][idx] - maps[i + 1][idx]) > 1)return false;
		}
	}
	else if (type == 'h') {
		for (int i = 0; i < N - 1; i++) {
			if (abs(maps[idx][i] - maps[idx][i + 1]) > 1)return false;
		}
	}
	else {
		cout << "Mistake Use\n";
		return false;
	}

	return true;
}

inline bool Boundary(int r, int c) {
	return !(r < 0 || r >= N || c < 0 || c >= N);
}

inline bool NeedRamp(int cr, int cc, int nr, int nc) {
	return maps[cr][cc] - 1 == maps[nr][nc];
}

/// <summary>
/// NeedRamp에서 true를 받은 cr, cc를 인자로 넣어야 합니다.
/// </summary>
bool CanInstall(int r, int c, EDir dir, const vector<int>& visited) {
	int originValue = maps[r][c];
	for (int i = 0; i < L; i++) {
		r += dr[(int)dir];
		c += dc[(int)dir];
		int idx;
		if ((int)dir % 2 == 0)
			idx = r;
		else
			idx = c;
		if (!Boundary(r, c))
			return false;
		if (visited[idx])
			return false;
		if (maps[r][c] != originValue - 1)
			return false;
	}

	return true;
}

/// <summary>
/// NeedRamp에서 true를 받은 cr, cc를 인자로 넣어야 합니다.
/// </summary>
void Install(int r, int c, EDir dir, vector<int>& visited) {
	for (int i = 0; i < L; i++) {
		r += dr[(int)dir];
		c += dc[(int)dir];
		int idx;
		if ((int)dir % 2 == 0)
			idx = r;
		else
			idx = c;
		visited[idx] = true;
	}
}

bool Check(int idx, char type) {
	vector<int> visited(N);

	for (int i = 0; i < N - 1; i++) {
		int cr, cc, nr, nc;
		if (type == 'v') {
			cc = nc = idx;
			cr = i, nr = i + 1;
		}
		else {
			cr = nr = idx;
			cc = i, nc = i + 1;
		}

		int delta = maps[nr][nc] - maps[cr][cc];
		if (delta == 0) continue;
		if (delta == 1) {
			if (!CanInstall(nr, nc, type == 'v' ? UP : LEFT, visited)) return false;
			Install(nr, nc, type == 'v' ? UP : LEFT, visited);
		}
		else if (delta == -1) {
			if (!CanInstall(cr, cc, type == 'v' ? DOWN : RIGHT, visited)) return false;
			Install(cr, cc, type == 'v' ? DOWN : RIGHT, visited);
		}
	}

	return true;
}

void Solution() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (CanCandidate(i, 'v')) {
			ret += Check(i, 'v');
		}
		if (CanCandidate(i, 'h')) {
			ret += Check(i, 'h');
		}
	}
	cout << ret << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 1;
	//cin >> T;
	while (T--) {
		if (!Inputs()) break;
		Solution();
	}

	return 0;
}