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
char maps[50][50];
int visited[50][50];

bool Inputs() {
	cin >> N >> M;
	FOR(i, N)
		FOR(j, M)
		cin >> maps[i][j];

	return true;
}

bool IsValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M)return false;
	return true;
}

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

bool DFS(int r, int c, int br, int bc) {

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		// 범위를 벗어나지 않고
		if (IsValid(nr, nc)) {
			// 이전에 온 방향은 아니며 현재 값과 같아야 하고
			if (nr != br || nc != bc) {
				if (maps[r][c] == maps[nr][nc]) {
					// 방문했던 영역이라면 싸이클
					if (visited[nr][nc]) {
						return true;
					}
					else {
						visited[nr][nc] = true;
						if (DFS(nr, nc, r, c)) {
							return true;
						}
						visited[nr][nc] = false;
					}
				}

			}
		}
	}

	return false;
}

void Solution() {
	FOR(i, N)
		FOR(j, M) {
		if (!visited[i][j]) {
			visited[i][j] = true;
			if (DFS(i, j, i, j)) {
				cout << "Yes\n";
				return;
			}
			visited[i][j] = false;
		}
	}

	cout << "No\n";
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