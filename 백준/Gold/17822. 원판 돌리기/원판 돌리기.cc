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

int N, M, T;
vector<vector<int>> maps;

struct Command {
	int idx;
	int ccw;
	int cnt;
};
vector<Command> commands;

bool Inputs() {
	cin >> N >> M >> T;
	maps.resize(N, vector<int>(M));
	FOR(r, N)
		FOR(c, M)
		cin >> maps[r][c];

	commands.resize(T);
	FOR(i, T) {
		int idx, ccw, cnt;
		cin >> commands[i].idx >> commands[i].ccw >> commands[i].cnt;
		commands[i].idx;
	}

	return true;
}

// 회전시키기
// 인접 수 찾기
// 평균 구해서 +1, -1

void Rotate(Command comm) {
	for (int k = comm.idx; k <= N; k += comm.idx) {
		vector<int> tmp = maps[k - 1];
		for (int i = 0; i < M; i++) {
			maps[k - 1][i] = comm.ccw ? tmp[(i + comm.cnt) % M] : tmp[(i - comm.cnt + M) % M];
		}
	}
}

struct Pos {
	int r, c;
};
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

bool IsValid(int r, int c, const vector<vector<int>>& visited, int val) {
	return !(r < 0 || r >= N || c < 0 || c >= M) && !visited[r][c] && maps[r][c] == val;
}

bool BFS(int r, int c, vector<vector<int>>& visited) {
	queue<Pos> q;
	q.push({ r, c });
	visited[r][c] = true;
	if (maps[r][c] == 0) return false;
	int origin = maps[r][c];
	bool ret = false;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dr[i];
			int nc = (cur.c + dc[i] + M) % M;
			if (IsValid(nr, nc, visited, origin)) {
				visited[nr][nc] = true;
				ret = true;
				maps[nr][nc] = 0;
				q.push({ nr, nc });
			}
		}
	}
	if (ret)
		maps[r][c] = 0;
	return ret;
}

bool Erase() {
	vector<vector<int>> visited(N, vector<int>(M));
	bool haveErase = false;
	FOR(r, N)
		FOR(c, M) {
		if (!visited[r][c]) {
			haveErase |= BFS(r, c, visited);
		}
	}
	return haveErase;
}

int Counting() {
	int ret = 0;
	FOR(r, N)
		FOR(c, M)
		ret += maps[r][c];
	return ret;
}

void Everage() {
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (maps[i][j] == 0)continue;
			sum += maps[i][j];
			cnt++;
		}
	}

	double avrg = (double)sum / cnt;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			sum += maps[i][j];
		for (int j = 0; j < M; j++) {
			if (maps[i][j] == 0) continue;
			if (maps[i][j] > avrg) {
				maps[i][j]--;
			}
			else if (maps[i][j] < avrg) {
				maps[i][j]++;
			}
		}
	}
}

void Solution() {
	for (int i = 0; i < T; i++) {
		Rotate(commands[i]);
		if (!Erase()) {
			Everage();
		}
		//PrintVec(maps);
		//cout << '\n';
	}

	cout << Counting();
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