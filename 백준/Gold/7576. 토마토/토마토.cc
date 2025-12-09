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
bool Inputs() {
	cin >> M >> N;
	maps.resize(N, vector<int>(M));
	FOR(r, N)
		FOR(c, M)
		cin >> maps[r][c];

	return true;
}

bool IsValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M)return false;
	return maps[r][c] == 0;
}

bool IsAllRipe() {
	FOR(r, N)
		FOR(c, M) {
		if (maps[r][c] == 0) return false;
	}

	return true;
}

void Solution() {
	int ret = 0;

	queue<pair<int, int>> q;
	FOR(r, N)
		FOR(c, M) {
		if (maps[r][c] == 1) {
			q.push({ r, c });
		}
	}

	while (!q.empty()) {
		int size = q.size();
		ret++;
		while (size--) {
			auto pos = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nr = pos.first + dr[i];
				int nc = pos.second + dc[i];

				if (IsValid(nr, nc)) {
					maps[nr][nc] = 1;
					q.push({ nr, nc });
				}
			}
		}
	}


	if (IsAllRipe()) {
		cout << ret - 1 << '\n';
	}
	else {
		cout << -1 << '\n';
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