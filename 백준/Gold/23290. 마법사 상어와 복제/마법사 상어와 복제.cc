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

// 1. 복제 마법을 검. 이건 마지막에 나타나기때문에 현재의 맵 상태를 보관해야 함
// 2. 물고기가 모두 이동을 함. 이는 물고기 냄새, 상어, 다른 물고기가 있어서는 안됨. 물고기는 반시계 45도 회전을 함
//		물고기가 이동할 수 없으면 이동하지 않음
// 3. 상어는 3칸 연속으로 이동함. 가장 물고기를 많이 먹는 순서로, 그 중 가장 빠른 사전순(상(1), 좌(2), 하(3), 우(4)가 기준인듯)으로 움직임
//		가는길에 있는 물고기들은 잡아먹히고, 냄새를 남김
// 4. 2턴 지속된 냄새는 사라짐
// 5. 1에서 건 복제 마법이 나타남. 원래 위치랑 방향을 그대로 가짐

enum EDir { LEFT, UL, UP, UR, RIGHT, DR, DOWN, DL, END };
int dr[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dc[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
EDir shrakPriority[4] = { UP, LEFT, DOWN, RIGHT };

// 물고기의 방향, 물고기의 유무, 냄새, 상어 를 모두 표현할 수 없나?
// 물고기의 방향과 유무는 EDir로 나타낼 수 있음
// 상어는 그냥 Pos하나 갖고, 냄새는 다른 vvec이면 될듯

// [r][c][물고기들] = 물고기들 방향
vector<vector<vector<EDir>>> maps;
vector<vector<int>> smells;
struct Pos {
	int r = 0, c = 0;
};
Pos sharkPos;

int M, S;
bool Inputs() {
	cin >> M >> S;
	maps.resize(4, vector<vector<EDir>>(4));
	smells.resize(4, vector<int>(4, 0));
	for (int i = 0; i < M; i++) {
		int r, c, d;
		cin >> r >> c >> d;
		maps[r - 1][c - 1].push_back(EDir(d - 1));
	}

	cin >> sharkPos.r >> sharkPos.c;
	sharkPos.r--;
	sharkPos.c--;
	return true;
}

inline bool Boundary(int r, int c) {
	return !(r < 0 || r >= 4 || c < 0 || c >= 4);
}

inline bool HasSmell(int r, int c) {
	return smells[r][c] > 0;
}

inline bool IsSharkPos(int r, int c) {
	return sharkPos.r == r && sharkPos.c == c;
}

void FishMove(vector<vector<vector<EDir>>>& nextMap) {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			// [r][c]의 물고기들
			for (int k = 0; k < maps[r][c].size(); k++) {
				EDir dir = maps[r][c][k];
				bool cantMove = true;
				// 45도 회전
				for (int d = 0; d < 8; d++) {
					EDir nd = EDir((dir - d + 8) % 8);
					int nr = r + dr[nd];
					int nc = c + dc[nd];
					if (Boundary(nr, nc) && !HasSmell(nr, nc) && !IsSharkPos(nr, nc)) {
						nextMap[nr][nc].push_back(nd);
						cantMove = false;
						break;
					}
				}
				// 아무데도 못간 물고기
				if (cantMove) {
					nextMap[r][c].push_back(dir);
				}
			}
		}
	}
}

void SharkMove(vector<vector<vector<EDir>>>& nextMap) {
	// 가장 많이 먹는 경로 찾기
	int maxValue = -1;
	Pos path[3] = {};

	for (int i = 0; i < 4; i++) {
		EDir first = shrakPriority[i];
		int fr = sharkPos.r + dr[first];
		int fc = sharkPos.c + dc[first];
		if (!Boundary(fr, fc)) continue;
		int fsum = nextMap[fr][fc].size();
		for (int j = 0; j < 4; j++) {
			EDir second = shrakPriority[j];
			int sr = fr + dr[second];
			int sc = fc + dc[second];
			if (!Boundary(sr, sc))continue;
			int ssum = nextMap[sr][sc].size();
			if (sr == fr && sc == fc) ssum = 0;

			for (int k = 0; k < 4; k++) {
				EDir third = shrakPriority[k];
				int tr = sr + dr[third];
				int tc = sc + dc[third];
				if (!Boundary(tr, tc)) continue;
				int tsum = nextMap[tr][tc].size();
				if ((tr == sr && tc == sc) || (tr == fr && tc == fc)) tsum = 0;

				if (fsum + ssum + tsum > maxValue) {
					maxValue = fsum + ssum + tsum;
					path[0] = { fr, fc };
					path[1] = { sr, sc };
					path[2] = { tr, tc };
				}
			}
		}
	}

	// 진짜 이동 및 물고기 먹어서 냄새 남기기
	for (int i = 0; i < 3; i++) {
		int r = path[i].r;
		int c = path[i].c;
		if (!nextMap[r][c].empty()) {
			nextMap[r][c].clear();
			smells[r][c] = 3;
		}
	}
	sharkPos = path[2];
}

void TimeFlow() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (smells[i][j] != 0) {
				smells[i][j]--;
			}
		}
	}
}

void Manifest(vector<vector<vector<EDir>>>& nextMap) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (!maps[i][j].empty()) {
				nextMap[i][j].insert(nextMap[i][j].end(), maps[i][j].begin(), maps[i][j].end());
			}
		}
	}

	swap(nextMap, maps);
}

int CountFish() {
	int ret = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ret += maps[i][j].size();
		}
	}
	return ret;
}

void Solution() {
	for (int i = 0; i < S; i++) {
		// 복제마법
		vector<vector<vector<EDir>>> nextMap(4, vector<vector<EDir>>(4));

		// 물고기 이동
		FishMove(nextMap);

		// 상어 이동
		SharkMove(nextMap);

		// 냄새 줄이기
		TimeFlow();

		// 복제한거 나타나기
		Manifest(nextMap);
	}

	cout << CountFish();
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