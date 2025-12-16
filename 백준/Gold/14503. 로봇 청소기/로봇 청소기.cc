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
int maps[50][50];
pair<int, int> roboPos;
enum EDir { UP, RIGHT, DOWN, LEFT };
EDir dir;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int cleanCnt = 0;
// 현재 칸이 청소되었는지
// 청소
// 주변 4칸이 모두 청소되었는지
// 후진
// 후진할 수 없다면 작동 중지
// 청소안된 칸이 있으면 반시계 방향 90도 회전
// 앞쪽 칸이 청소되지 않았으면 빈 칸인경우 전진
// 반복

/// <summary>
/// r과 c가 맵 범위 안에 들어오는지를 검사하는 함수
/// </summary>
inline bool Boundary(int r, int c) {

	return !(r < 0 || r >= N || c < 0 || c >= M);
}

/// <summary>
/// r과 c가 청소 안된 구역인지 검사하는 함수
/// </summary>
inline bool IsDirty(int r, int c) {
	return Boundary(r, c) && maps[r][c] == 0;
}

/// <summary>
/// 주변 4칸에 청소 안된 구역이 존재하는지 검사하는 함수
/// </summary>
bool DirtyAreaExsist(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (IsDirty(nr, nc)) return true;
	}
	return false;
}

/// <summary>
/// dir을 반시계 방향으로 회전하는 함수입니다.
/// </summary>
EDir Rotate(EDir dir, int cnt = 1) {
	return EDir(((int)dir - cnt + 4) % 4);
}

/// <summary>
/// 후진이 가능한지 판단하는 함수입니다.
/// </summary>
inline bool CanReverse(int r, int c, EDir dir) {
	dir = Rotate(dir, 2);
	int nr = r + dr[(int)dir];
	int nc = c + dc[(int)dir];

	return Boundary(nr, nc) && maps[nr][nc] != 1;
}

inline void MoveForward(int r, int c, EDir dir) {
	//cout << __FUNCTION__ << '\n';
	int nr = r + dr[(int)dir];
	int nc = c + dc[(int)dir];
	roboPos.first = nr;
	roboPos.second = nc;
}

inline void MoveBack(int r, int c, EDir dir) {
	//cout << __FUNCTION__ << '\n';
	dir = Rotate(dir, 2);
	int nr = r + dr[(int)dir];
	int nc = c + dc[(int)dir];
	roboPos.first = nr;
	roboPos.second = nc;
}

inline void Clean(int r, int c) {
	maps[r][c] = 2;
	cleanCnt++;
}



bool Inputs() {
	int _dir;
	cin >> N >> M;
	cin >> roboPos.first >> roboPos.second >> _dir;
	dir = (EDir)_dir;
	FOR(r, N)
		FOR(c, M)
		cin >> maps[r][c];

	return true;
}

void Solution() {
	while (true) {
		//cout << roboPos.first << ' ' << roboPos.second << '\n';
		if (IsDirty(roboPos.first, roboPos.second))
			Clean(roboPos.first, roboPos.second);

		if (DirtyAreaExsist(roboPos.first, roboPos.second)) {
			for (int i = 0; i < 4; i++) {
				dir = Rotate(dir);
				int nr = roboPos.first + dr[(int)dir];
				int nc = roboPos.second + dc[(int)dir];
				if (IsDirty(nr, nc)) {
					MoveForward(roboPos.first, roboPos.second, dir);
					break;
				}
			}
		}
		else {
			if (CanReverse(roboPos.first, roboPos.second, dir)) {
				MoveBack(roboPos.first, roboPos.second, dir);
			}
			else {
				break;
			}
		}
	}

	cout << cleanCnt << '\n';
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