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
int N;

int maps[100][100];
int visited[100][100];
int minValue = INF, maxValue = 0;
bool Inputs() {
	cin >> N;
	FOR(i, N)
		FOR(j, N) {
		cin >> maps[i][j];
		minValue = min(minValue, maps[i][j]);
		maxValue = max(maxValue, maps[i][j]);
	}


	return true;
}

bool IsValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= N) return false;
	return !visited[r][c];
}

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

int DFS(int r, int c) {
	int ret = 1;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (IsValid(nr, nc)) {
			visited[nr][nc] = true;
			ret += DFS(nr, nc);
		}
	}

	return ret;
}

int GetSafeAreaCnt(int limit) {
	memset(visited, 0, sizeof(visited));
	FOR(i, N)
		FOR(j, N) {
		if (maps[i][j] <= limit)
			visited[i][j] = true;
	}

	int ret = 0;

	FOR(i, N)
		FOR(j, N) {
		if (IsValid(i, j)) {
			visited[i][j] = true;
			DFS(i, j);
			ret++;
		}
	}

	return ret;
}

void Solution() {
	int ret = 0;
	for (int i = minValue - 1; i < maxValue; i++) {
		ret = max(ret, GetSafeAreaCnt(i));
	}
	cout << ret << '\n';
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