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

int N, M;
vector<vector<int>> maps;
vector<vector<int>> cache;

bool Inputs() {

	cin >> N >> M;
	maps.resize(N, vector<int>(M));
	cache.resize(N, vector<int>(M, -1));
	FOR(i, N)
		FOR(j, M)
		cin >> maps[i][j];

	return true;
}

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

bool IsValid(int r, int c, int cur) {
	if (r < 0 || r >= N || c < 0 || c >= M) return false;
	return cur > maps[r][c];
}

int DFS(int r, int c) {
	if (r == N - 1 && c == M - 1)
		return 1;

	int& ret = cache[r][c];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (IsValid(nr, nc, maps[r][c])) {
			ret += DFS(nr, nc);
		}
	}

	return ret;
}

void Solution() {
	cout << DFS(0, 0) << '\n';
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