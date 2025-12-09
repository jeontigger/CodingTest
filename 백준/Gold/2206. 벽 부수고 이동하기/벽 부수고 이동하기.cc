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

int N, M;
vector<vector<int>> maps;
vector<vector<int>> visited(N, vector<int>(M, 2));
bool Inputs() {
	cin >> N >> M;
	maps.resize(N, vector<int>(M));
	visited.resize(N, vector<int>(M, 2));
	FOR(r, N)
		FOR(c, M) {
		char ch;
		cin >> ch;
		maps[r][c] = ch - '0';
	}


	return true;
}

struct Pos {
	int r;
	int c;
	int b;
	int s;
};

bool IsValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M)return false;
	return true;
}

void Solution() {

	queue<Pos>q;
	q.push({ 0, 0, 0, 0 });
	visited[0][0] = 0;

	while (!q.empty()) {
		Pos pos = q.front();
		q.pop();

		//cout << pos.r << ' ' << pos.c << ' ' << pos.b << ' ' << pos.s << '\n';

		if (pos.r == N - 1 && pos.c == M - 1) {
			cout << pos.s + 1 << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nr = pos.r + dr[i];
			int nc = pos.c + dc[i];

			if (IsValid(nr, nc)) {
				int nb = pos.b;
				if (maps[nr][nc] == 1) {
					nb++;
				}

				if (visited[nr][nc] > nb) {
					visited[nr][nc] = nb;
					q.push({ nr, nc, nb, pos.s + 1 });
				}
			}
		}
	}

	cout << -1 << '\n';
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