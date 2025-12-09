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
int dr[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dc[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int N;
int kr, kc, tr, tc;
vector<vector<int>> visited;
bool Inputs() {
	cin >> N;
	cin >> kr >> kc >> tr >> tc;

	visited.assign(N, vector<int>(N, 0));
	return true;
}

bool IsValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= N)return false;
	return !visited[r][c];
}

void Solution() {
	queue<pair<int, int>> q;
	q.push({ kr, kc });
	visited[kr][kc] = true;

	int ret = 0;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			auto pos = q.front();
			q.pop();

			if (pos.first == tr && pos.second == tc) {
				cout << ret << '\n';
				return;
			}

			for (int i = 0; i < 8; i++) {
				int nr = pos.first + dr[i];
				int nc = pos.second + dc[i];
				if (IsValid(nr, nc)) {
					visited[nr][nc] = true;
					q.push({ nr, nc });
				}
			}
		}
		ret++;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 1;
	cin >> T;
	while (T--) {
		if (!Inputs()) break;
		Solution();
	}

	return 0;
}