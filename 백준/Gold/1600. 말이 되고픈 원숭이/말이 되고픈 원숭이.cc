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
int kr[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int kc[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

int K, W, H;
vector<vector<int>> maps;

bool Inputs() {
	cin >> K >> W >> H;
	maps.resize(H, vector<int>(W));
	FOR(r, H)
		FOR(c, W)
		cin >> maps[r][c];
	return true;
}

struct Pos {
	int r;
	int c;
	int k;
};

inline bool IsValid(int r, int c, int k, const vector<vector<int>>& visited) {
	return !(r < 0 || r >= H || c < 0 || c >= W) && k <= K && visited[r][c] > k && !maps[r][c];
}

void Solution() {

	queue<Pos>q;
	q.push({ 0, 0, 0 });
	vector<vector<int>> visited(H, vector<int>(W, INF));
	visited[0][0] = true;

	int ret = -1;
	while (!q.empty()) {
		ret++;

		int size = q.size();
		while (size--) {
			Pos pos = q.front();
			q.pop();

			if (pos.r == H - 1 && pos.c == W - 1) {
				cout << ret << '\n';
				return;
			}

			for (int i = 0; i < 4; i++) {
				int nr = pos.r + dr[i];
				int nc = pos.c + dc[i];
				if (IsValid(nr, nc, pos.k, visited)) {
					visited[nr][nc] = pos.k;
					q.push({ nr, nc, pos.k });
				}
			}

			for (int i = 0; i < 8; i++) {
				int nr = pos.r + kr[i];
				int nc = pos.c + kc[i];
				if (IsValid(nr, nc, pos.k + 1, visited)) {
					visited[nr][nc] = pos.k + 1;
					q.push({ nr, nc, pos.k + 1 });
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