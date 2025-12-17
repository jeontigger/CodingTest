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

enum EDir {
	UP, UL, LEFT, DL, DOWN, DR, RIGHT, UR
};
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

struct Node {
	int fish;
	EDir dir;
};

int N = 4;
vector<vector<Node>> maps;
vector<int> ate;
unordered_map<int, pair<int, int>> fishPos;

bool Inputs() {
	maps.resize(N, vector<Node>(N));
	ate.resize(N * N + 1);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int f, d;
			cin >> f >> d;
			maps[i][j].fish = f;
			maps[i][j].dir = (EDir)(d - 1);
			fishPos[f] = { i, j };
		}
	}

	return true;
}

// 상어를 놓고 먹는 것
// 물고기 이동
// 상어가 더이상 이동하지 못한다면 

inline bool Boundary(int r, int c) {
	return !(r < 0 || r >= N || c < 0 || c >= N);
}

constexpr int SHARK = 20;

bool CanSwap(int r, int c) {

	return Boundary(r, c) && maps[r][c].fish != SHARK;
}

void FishSwap(int r, int c, int nr, int nc) {
	auto origin = maps[r][c];
	auto target = maps[nr][nc];

	fishPos[target.fish] = { r, c };
	fishPos[origin.fish] = { nr, nc };

	maps[r][c] = target;
	maps[nr][nc] = origin;
}

void ChangeFishPos() {
	for (int i = 1; i < ate.size(); i++) {
		if (ate[i])continue;
		auto pos = fishPos[i];
		if (maps[pos.first][pos.second].fish != i) {
			cout << "물고기 위치랑 물고기 노드가 일치하지 않습니다 \n";
		}
		for (int i = 0; i < 8; i++) {
			auto dir = maps[pos.first][pos.second].dir;
			int nr = pos.first + dr[dir];
			int nc = pos.second + dc[dir];
			if (CanSwap(nr, nc)) {
				FishSwap(pos.first, pos.second, nr, nc);
				break;
			}
			maps[pos.first][pos.second].dir = (EDir)((maps[pos.first][pos.second].dir + 1) % 8);
		}
	}
}

void PrintFish() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << maps[i][j].fish << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void PrintDir() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << maps[i][j].dir << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void PrintPos() {
	for (int i = 1; i <= 16; i++) {
		cout << fishPos[i].first << ' ' << fishPos[i].second << '\n';
	}
}

int MaxEat(int r, int c) {
	int origin = maps[r][c].fish;
	int ret = 0;
	EDir dir = maps[r][c].dir;
	maps[r][c].fish = SHARK;
	ate[origin] = true;

	// 물고기 변환
	auto copymaps = maps;
	auto copypos = fishPos;
	ChangeFishPos();
	//PrintPos();

	maps[r][c].fish = 0;
	for (int i = 0; i < N; i++) {
		int nr = r + dr[dir] * (i + 1);
		int nc = c + dc[dir] * (i + 1);

		if (!Boundary(nr, nc)) continue;
		if (1 <= maps[nr][nc].fish && maps[nr][nc].fish <= 16) {
			ret = max(ret, MaxEat(nr, nc));
		}
	}
	maps = copymaps;
	fishPos = copypos;
	maps[r][c].fish = origin;
	ate[origin] = false;

	return ret + origin;
}

void Solution() {
	cout << MaxEat(0, 0);
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