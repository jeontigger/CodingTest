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

// 격자는  NxN, 파이어볼 M개, 격자는 계속 순환함
// 파이어볼 위치는 ri, ci, 질량은 mi, 방향은 di, 속력은 si

// 방향 순서
enum EDir { UP, UR, RIGHT, DR, DOWN, DL, LEFT, UL, END };
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

// 규칙
// 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동
// 이동하는 중은 계산 x
// 이동이 모두 끝나면 2개 이상의 파이어볼이 있는 칸에서 다음과 같은 일이 일어남
	// 파이어볼은 모두 하나로 합쳐지고, 4개로 나누어짐
	// 질량은 전체합 / 5, 속력은 전체합 / 합쳐진 파이어볼 개수 => 소수점은 모두 내림처리
	// 모두 홀수이거나 모두 짝수면 방향이 0, 2,4, 6이 되고, 아니면 1, 3, 5, 7이 됨
	// 질량이 0인 파이어볼은 소멸됨

// 결과
// K번 이동 후 파이어볼의 질량 합

int N, M, K;
struct Pos {
	int r = 0, c = 0;
};

struct FireBall {
	Pos pos = { 0, 0 };
	int mass = 0;
	int speed = 0;
	EDir dir = END;
};

vector<FireBall> fireBalls;

bool Inputs() {
	cin >> N >> M >> K;
	fireBalls.resize(M);
	for (int i = 0; i < M; i++) {
		int dir;
		cin >> fireBalls[i].pos.r >> fireBalls[i].pos.c >> fireBalls[i].mass >> fireBalls[i].speed >> dir;
		fireBalls[i].dir = (EDir)dir;
		fireBalls[i].pos.r--;
		fireBalls[i].pos.c--;
	}
	return true;
}

int CountingMass() {
	int ret = 0;
	for (int i = 0; i < fireBalls.size(); i++) {
		ret += fireBalls[i].mass;
	}
	return ret;
}

FireBall Move(FireBall fb) {
	int r = fb.pos.r;
	int c = fb.pos.c;
	EDir d = fb.dir;
	int s = fb.speed;

	// origin + delta + Min_Max % N
	int nr = (r + dr[d] * s + N * 250) % N;
	int nc = (c + dc[d] * s + N * 250) % N;

	fb.pos.r = nr;
	fb.pos.c = nc;
	return fb;
}

void PrintFireBalls() {
	for (int i = 0; i < fireBalls.size(); i++) {
		cout << fireBalls[i].pos.r << ' ' << fireBalls[i].pos.c << '\n';
	}
}

vector<FireBall> Divide(vector<FireBall>& fbs) {
	if (fbs.size() == 1) {
		return fbs;
	}

	// 속력 및 질량 구하기
	int ms = 0, ss = 0;
	Pos pos = fbs[0].pos;

	// 방향 구하기
	bool isOdd = false;
	bool isEven = false;
	for (int i = 0; i < fbs.size(); i++) {
		ms += fbs[i].mass;
		ss += fbs[i].speed;

		if (fbs[i].dir % 2 == 0) {
			isEven = true;
		}
		else {
			isOdd = true;
		}
	}
	int nm = ms / 5;
	if (nm == 0) return {};
	int ns = ss / fbs.size();

	vector<FireBall> ret(4);
	for (int i = 0; i < 4; i++) {
		ret[i].dir = EDir(isOdd ^ isEven ? 2 * i : 1 + 2 * i);
		ret[i].mass = nm;
		ret[i].speed = ns;
		ret[i].pos = pos;
	}

	return ret;
}

void Step() {
	// [r][c][fireballs]
	vector<vector<vector<FireBall>>> maps(N, vector<vector<FireBall>>(N));

	// 1. 파이어볼 이동
	for (int i = 0; i < fireBalls.size(); i++) {
		auto ret = Move(fireBalls[i]);
		auto pos = ret.pos;
		maps[pos.r][pos.c].push_back(ret);
	}

	// 2. 파이어볼 중복 처리
	fireBalls.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!maps[i][j].empty()) {
				auto vec = Divide(maps[i][j]);
				if (vec.empty())continue;
				fireBalls.insert(fireBalls.end(), vec.begin(), vec.end());
			}
		}
	}

}

void Solution() {
	for (int i = 0; i < K; i++) {
		Step();
		//PrintFireBalls();
	}

	cout << CountingMass();
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