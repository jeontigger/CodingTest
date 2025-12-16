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

int N, M, sr, sc, K;
int maps[20][20];
int commands[1000];

enum EDir { RIGHT, LEFT, UP, DOWN };
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { 1, -1, 0, 0 };

int dice[3][3];
int diceBack;

bool Inputs() {
	cin >> N >> M >> sr >> sc >> K;
	FOR(r, N)
		FOR(c, M)
		cin >> maps[r][c];

	FOR(i, K) {
		cin >> commands[i];
		commands[i]--;
	}

	memset(dice, 0, sizeof(dice));
	diceBack = 0;

	return true;
}

inline bool Boundary(int r, int c) {
	return !(r < 0 || r >= N || c < 0 || c >= M);
}

bool Move(int comm) {
	int nr = sr + dr[comm];
	int nc = sc + dc[comm];
	if (!Boundary(nr, nc))return false;

	int back = diceBack;

	switch (comm)
	{
	case (int)RIGHT:
		diceBack = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = back;
		break;
	case (int)LEFT:
		diceBack = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = back;
		break;
	case (int)UP:
		diceBack = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = back;
		break;
	case (int)DOWN:
		diceBack = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = back;
		break;
	default:
		cout << "잘못된 명령어 입력입니다.\n";
		break;
	}

	if (maps[nr][nc] == 0) {
		maps[nr][nc] = diceBack;
	}
	else {
		diceBack = maps[nr][nc];
		maps[nr][nc] = 0;
	}

	sr = nr;
	sc = nc;
	return true;
}

void Solution() {
	for (int i = 0; i < K; i++) {
		int comm = commands[i];
		if (Move(comm))
			cout << dice[1][1] << '\n';
	}
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