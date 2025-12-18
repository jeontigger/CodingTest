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

enum EDir { LEFT, UL, UP, UR, RIGHT, DR, DOWN, DL, END };
int dr[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dc[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

struct Pos {
	int r = 0, c = 0;
};

struct Commands {
	EDir dir = END;
	int speed = 0;
};

int N, M;
vector<vector<int>> maps;
vector<Commands> commands;

bool Inputs() {
	cin >> N >> M;
	maps.resize(N, vector<int>(N));
	commands.resize(M);
	FOR(r, N)
		FOR(c, N)
		cin >> maps[r][c];

	FOR(i, M) {
		int dir;
		cin >> dir >> commands[i].speed;
		commands[i].dir = (EDir)(dir - 1);
	}

	return true;
}

// 구름 첫 생성
// 루프
	// 구름 이동
	// 구름 생성

vector<Pos> clouds;
void CloudInit() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			clouds.push_back({ N - 1 - i, j });
		}
	}
}

inline bool Boundary(int r, int c) {
	return !(r < 0 || r >= N || c < 0 || c >= N);
}

inline Pos LoopPos(int r, int c) {
	return { (r + N * 50) % N,(c + N * 50) % N };
}

Pos Move(Pos cloud, EDir dir, int speed) {
	int nr = cloud.r + dr[dir] * speed;
	int nc = cloud.c + dc[dir] * speed;
	return LoopPos(nr, nc);
}

void CloudMove(EDir dir, int speed) {
	for (int i = 0; i < clouds.size(); i++) {
		clouds[i] = Move(clouds[i], dir, speed);
	}
}

void Raining() {
	for (int i = 0; i < clouds.size(); i++) {
		maps[clouds[i].r][clouds[i].c]++;
	}
}

/// <summary>
/// 물이 있는지 검사합니다. 이 때 경계를 넘지 못합니다.
/// </summary>
inline bool HasWater(int r, int c) {
	return Boundary(r, c) && maps[r][c] != 0;
}

/// <summary>
/// 주변에 있는 물의 개수를 세는 함수입니다.
/// </summary>
int CountingAroundWater(int r, int c) {
	int ret = 0;
	for (int i = 1; i < END; i += 2) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		ret += HasWater(nr, nc);
	}

	return ret;
}

/// <summary>
/// 대각선 방향의 물 개수만큼 증가
/// </summary>
void CopyBug() {
	auto copymap = maps;
	for (int i = 0; i < clouds.size(); i++) {
		auto pos = clouds[i];
		int res = CountingAroundWater(pos.r, pos.c);

		// 여기서 문제가 있는데, 이전 값을 저장해야겠지?
		copymap[pos.r][pos.c] += res;
	}
	swap(copymap, maps);
}

void CloudGen() {
	vector<Pos> nextClouds;
	vector<vector<int>> visited(N, vector<int>(N));
	for (int i = 0; i < clouds.size(); i++) {
		auto pos = clouds[i];
		visited[pos.r][pos.c] = true;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && maps[i][j] >= 2) {
				nextClouds.push_back({ i, j });
				maps[i][j] -= 2;
			}
		}
	}
	swap(nextClouds, clouds);
}

int WaterAmount() {
	int ret = 0;

	FOR(r, N)
		FOR(c, N)
		ret += maps[r][c];

	return ret;
}

void PrintMaps() {
	PrintVec(maps);
	cout << '\n';
}

void Solution() {
	CloudInit();
	for (int i = 0; i < M; i++) {
		CloudMove(commands[i].dir, commands[i].speed);
		Raining();
		CopyBug();
		CloudGen();

		//PrintMaps();
	}

	cout << WaterAmount();
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