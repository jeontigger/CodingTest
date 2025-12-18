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

// NxN 격자 A[r][c]는 모래의 양을 뜻함
// 토네이도는 가운데부터 시작

int spreadPercent[5][5] = {
	{ 0, 0, 2, 0, 0},
	{ 0, 10, 7, 1, 0},
	{5, 0, 0, 0, 0},
	{0, 10, 7, 1, 0},
	{0, 0, 2, 0, 0}
};

enum EDir { LEFT, DOWN, RIGHT, UP };
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { -1, 0, 1, 0 };

int N;
vector<vector<int>> maps;
struct Pos {
	int r = 0, c = 0;
};
Pos tornadoPos;
EDir tornadoDir;
int sandTotal = 0;
bool Inputs() {
	cin >> N;
	maps.resize(N, vector<int>(N));
	FOR(r, N)
		FOR(c, N) {
		cin >> maps[r][c];
		sandTotal += maps[r][c];
	}

	tornadoPos.r = tornadoPos.c = N / 2;
	tornadoDir = LEFT;
	return true;
}

int moveCnt = 0;
int rotateCnt = 0;
int moveLevel = 1;

// 토네이도의 다음 포지션과 다음 방향을 반환
pair<Pos, EDir> NextTornadoPos() {
	auto pos = tornadoPos;
	auto dir = tornadoDir;
	int nr = pos.r + dr[dir];
	int nc = pos.c + dc[dir];

	moveCnt++;
	if (moveCnt == moveLevel) {
		moveCnt = 0;
		rotateCnt++;
		dir = (EDir)((dir + 1) % 4);
		if (rotateCnt == 2) {
			rotateCnt = 0;
			moveLevel++;
		}
	}

	return { {nr, nc}, dir };
}

void PrintTornadoPos() {
	cout << tornadoPos.r << ' ' << tornadoPos.c << ' ' << tornadoDir << '\n';
}

int CountingSandAmount() {
	int ret = 0;
	FOR(r, N)
		FOR(c, N)
		ret += maps[r][c];
	return ret;
}

inline bool Boundary(int r, int c) {
	return !(r < 0 || r >= N || c < 0 || c >= N);
}

int ConvertDir(int num) {
	return (num + 4 * 1000) % 4;
}

int PushSand(int r, int c, int sand, float percent) {
	int ret = sand * percent;
	if (Boundary(r, c)) {
		maps[r][c] += ret;
	}
	return ret;
}

void Spread() {
	// 어떤 위치인지, 어떤 방향인지에 따라 달라짐
	Pos pos = tornadoPos;
	EDir dir = tornadoDir;

	int sand = maps[pos.r][pos.c];
	maps[pos.r][pos.c] = 0;
	int spread = 0;

	// 진행 방향의 2칸 뒤로 5퍼
	int nr = pos.r + dr[dir] * 2;
	int nc = pos.c + dc[dir] * 2;
	spread += PushSand(nr, nc, sand, 0.05f);

	// 진행 방향의 수직 방향 2칸 뒤로 2퍼
	nr = pos.r + dr[ConvertDir(dir + 1)] * 2;
	nc = pos.c + dc[ConvertDir(dir + 1)] * 2;
	spread += PushSand(nr, nc, sand, 0.02f);
	nr = pos.r + dr[ConvertDir(dir - 1)] * 2;
	nc = pos.c + dc[ConvertDir(dir - 1)] * 2;
	spread += PushSand(nr, nc, sand, 0.02f);

	// 진행 방향의 수직 방향 1칸 뒤로 7퍼
	nr = pos.r + dr[ConvertDir(dir + 1)] * 1;
	nc = pos.c + dc[ConvertDir(dir + 1)] * 1;
	spread += PushSand(nr, nc, sand, 0.07f);
	nr = pos.r + dr[ConvertDir(dir - 1)] * 1;
	nc = pos.c + dc[ConvertDir(dir - 1)] * 1;
	spread += PushSand(nr, nc, sand, 0.07f);

	// 진행방향, 수직, 방향 1칸씩 뒤로 10퍼
	nr = pos.r + dr[ConvertDir(dir)] + dr[ConvertDir(dir + 1)];
	nc = pos.c + dc[ConvertDir(dir)] + dc[ConvertDir(dir + 1)];
	spread += PushSand(nr, nc, sand, 0.1f);
	nr = pos.r + dr[ConvertDir(dir)] + dr[ConvertDir(dir - 1)];
	nc = pos.c + dc[ConvertDir(dir)] + dc[ConvertDir(dir - 1)];
	spread += PushSand(nr, nc, sand, 0.1f);

	// 진행방향 반대, 수직 1칸씩 뒤로 1퍼
	nr = pos.r + dr[ConvertDir(dir + 2)] + dr[ConvertDir(dir + 1)];
	nc = pos.c + dc[ConvertDir(dir + 2)] + dc[ConvertDir(dir + 1)];
	spread += PushSand(nr, nc, sand, 0.01f);
	nr = pos.r + dr[ConvertDir(dir + 2)] + dr[ConvertDir(dir - 1)];
	nc = pos.c + dc[ConvertDir(dir + 2)] + dc[ConvertDir(dir - 1)];
	spread += PushSand(nr, nc, sand, 0.01f);

	// 진행방향 다음 칸 남은것
	nr = pos.r + dr[ConvertDir(dir)];
	nc = pos.c + dc[ConvertDir(dir)];
	PushSand(nr, nc, sand - spread, 1.f);
}

void PrintSandMap() {
	cout << "================\n";
	PrintVec(maps);
}

void Solution() {

	// 토네이도가 0, 0에 도착하면 종료
	int step = 1;
	while (tornadoPos.r != 0 || tornadoPos.c != 0) {
		// 토네이도의 이동 경로 확보
		auto nextData = NextTornadoPos();
		tornadoPos = nextData.first;
		// 모래 퍼지기
		Spread();
		tornadoDir = nextData.second;
		//PrintTornadoPos();
		//cout << "step: " << step << '\n';
		//PrintSandMap();
		//cout << sandTotal - CountingSandAmount() << '\n' << '\n';
		step++;
	}

	// 남간 모래 양 출력
	cout << sandTotal - CountingSandAmount() << '\n';
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