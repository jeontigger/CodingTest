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
char maps[20][20];
int visited[128];
int cache[20][20];

bool Inputs() {
	cin >> N >> M;
	FOR(i, N)
		FOR(j, M)
		cin >> maps[i][j];

	memset(visited, 0, sizeof(visited));
	memset(cache, -1, sizeof(cache));

	return true;
}



bool IsValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M)return false;

	return !visited[maps[r][c]];
}

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

int DFS(int r, int c) {
	int ret = 0;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (IsValid(nr, nc)) {
			visited[maps[nr][nc]] = true;
			ret = max(ret, DFS(nr, nc));
			visited[maps[nr][nc]] = false;
		}
	}
	return ret + 1;
}

void Solution() {
	int ret = 0;

	visited[maps[0][0]] = true;
	ret = DFS(0, 0);

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