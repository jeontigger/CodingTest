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
#define FOR(idx, limit) for(int idx = 0; idx < limit; idx++)
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

int N;
vector<vector<int>> maps;

struct Pos {
	int r;
	int c;
	int t;
};

Pos baby;
int babySize, babyExp;

bool Inputs() {
	cin >> N;
	maps.resize(N, vector<int>(N));
	babySize = 2;
	FOR(i, N)
		FOR(j, N) {
		cin >> maps[i][j];
		if (maps[i][j] == 9) {
			baby.r = i;
			baby.c = j;
			maps[i][j] = 0;
		}
	}

	return true;
}

bool CanEat(Pos pos) {
	return maps[pos.r][pos.c] != 0 && maps[pos.r][pos.c] < babySize;
}

void Eat(Pos pos) {
	maps[pos.r][pos.c] = 0;
	baby = pos;
	baby.t = 0;
	babyExp++;
	if (babyExp == babySize) {
		babySize++;
		babyExp = 0;
	}
}

bool CanMove(int r, int c, const vector<vector<int>>& visited) {
	return !(r < 0 || r >= N || c < 0 || c >= N) && !visited[r][c] && maps[r][c] <= babySize;
}

struct cmp {
	bool operator()(const Pos& p1, const Pos& p2) {
		if (p1.t != p2.t) {
			return p1.t > p2.t;
		}
		else if (p1.r != p2.r) {
			return p1.r > p2.r;
		}
		else {
			return p1.c > p2.c;
		}
	}
};


int BFS() {
	priority_queue<Pos, vector<Pos>, cmp> pq;
	pq.push(baby);
	vector<vector<int>> visited(N, vector<int>(N));
	visited[baby.r][baby.c] = true;

	int time = 0;
	while (!pq.empty()) {
		Pos pos = pq.top();
		pq.pop();

		if (CanEat(pos)) {
			Eat(pos);
			//cout << pos.r << ' ' << pos.c << ' ' << pos.t << '\n';
			return pos.t;
		}

		for (int i = 0; i < 4; i++) {
			int nr = pos.r + dr[i];
			int nc = pos.c + dc[i];
			if (CanMove(nr, nc, visited)) {
				visited[nr][nc] = true;
				pq.push({ nr, nc, pos.t + 1 });
			}
		}
	}

	return 0;
}

void Solution() {
	int ret = 0, time = 0;
	while (ret = BFS()) {
		time += ret;
	}

	cout << time << '\n';

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