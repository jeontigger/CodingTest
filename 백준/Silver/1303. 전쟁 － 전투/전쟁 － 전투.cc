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
int visited[100][100];
char maps[100][100];

bool Inputs() {
	cin >> M >> N;
	FOR(i, N)
		FOR(j, M)
		cin >> maps[i][j];

	return true;
}

bool IsValid(int r, int c, char cur) {
	if (r < 0 || r >= N || c < 0 || c >= M)return false;
	return !visited[r][c] && maps[r][c] == cur;
}

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

int DFS(int r, int c) {
	int ret = 1;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (IsValid(nr, nc, maps[r][c])) {
			visited[nr][nc] = true;
			ret += DFS(nr, nc);
		}
	}

	return ret;
}

void Solution() {
	int W = 0;
	int B = 0;
	FOR(i, N)
		FOR(j, M) {
		if (IsValid(i, j, maps[i][j])) {
			visited[i][j] = true;
			int ret = DFS(i, j);
			if (maps[i][j] == 'W') {
				W += ret * ret;
			}
			else {
				B += ret * ret;
			}
		}
	}

	cout << W << ' ' << B << '\n';
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