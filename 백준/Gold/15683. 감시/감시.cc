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

int N, M;
int maps[8][8];

struct CCTV {
	int r;
	int c;
	int type;
};
vector<CCTV> cctvs;

bool Inputs() {
	cin >> N >> M;
	FOR(r, N)
		FOR(c, M) {
		cin >> maps[r][c];
		if (1 <= maps[r][c] && maps[r][c] <= 5) {
			cctvs.push_back({ r, c, maps[r][c] });
			maps[r][c] = 0;
		}

	}

	return true;
}

inline bool Boundary(int r, int c) {
	return !(r < 0 || r >= N || c < 0 || c >= M);
}

inline bool IsValid(int r, int c) {
	return Boundary(r, c) && maps[r][c] != 6;
}
enum EDir { RIGHT, UP, LEFT, DOWN };
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };

void DrawStraight(int r, int c, int dir, int delta) {
	while (true) {
		if (!IsValid(r, c))return;

		maps[r][c] += 8 * delta;

		r += dr[dir];
		c += dc[dir];
	}
}

void Draw(CCTV cctv, int rotate, int delta) {
	if (cctv.type == 1) {
		DrawStraight(cctv.r, cctv.c, ((int)RIGHT + rotate) % 4, delta);
	}
	else if (cctv.type == 2) {
		DrawStraight(cctv.r, cctv.c, ((int)RIGHT + rotate) % 4, delta);
		DrawStraight(cctv.r, cctv.c, ((int)LEFT + rotate) % 4, delta);
	}
	else if (cctv.type == 3) {
		DrawStraight(cctv.r, cctv.c, ((int)RIGHT + rotate) % 4, delta);
		DrawStraight(cctv.r, cctv.c, ((int)UP + rotate) % 4, delta);
	}
	else if (cctv.type == 4) {
		DrawStraight(cctv.r, cctv.c, ((int)LEFT + rotate) % 4, delta);
		DrawStraight(cctv.r, cctv.c, ((int)UP + rotate) % 4, delta);
		DrawStraight(cctv.r, cctv.c, ((int)RIGHT + rotate) % 4, delta);
	}
	else if (cctv.type == 5) {
		DrawStraight(cctv.r, cctv.c, ((int)LEFT + rotate) % 4, delta);
		DrawStraight(cctv.r, cctv.c, ((int)UP + rotate) % 4, delta);
		DrawStraight(cctv.r, cctv.c, ((int)RIGHT + rotate) % 4, delta);
		DrawStraight(cctv.r, cctv.c, ((int)DOWN + rotate) % 4, delta);
	}
	else {
		cout << "잘못된 cctv type 입니다.\n";
	}
}

int CountingUnvisibleArea() {
	int ret = 0;
	FOR(r, N)
		FOR(c, M) {
		ret += (maps[r][c] == 0);
	}

	return ret;
}

int DFS(int idx) {
	if (idx == cctvs.size()) {
		return CountingUnvisibleArea();
	}

	int ret = INF;
	for (int rotate = 0; rotate < 4; rotate++) {
		Draw(cctvs[idx], rotate, 1);
		ret = min(ret, DFS(idx + 1));
		Draw(cctvs[idx], rotate, -1);
	}

	return ret;
}

void Solution() {
	cout << DFS(0);
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