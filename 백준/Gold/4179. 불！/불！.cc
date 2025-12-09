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
vector<vector<char>> maps;
bool Inputs() {
	cin >> N >> M;
	maps.resize(N, vector<char>(M));
	FOR(r, N)
		FOR(c, M)
		cin >> maps[r][c];
	return true;
}

bool CanEscape(int r, int c) {
	return r < 0 || r >= N || c < 0 || c >= M;
}

bool IsValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M)return false;
	return maps[r][c] == '.';
}

int Escape() {
	queue<pair<int, int>> jq;
	queue<pair<int, int>> fq;
	vector<vector<int>> visited(N, vector<int>(M));
	FOR(r, N)
		FOR(c, M) {
		if (maps[r][c] == 'J') {
			jq.push({ r, c });
			maps[r][c] = '.';
			visited[r][c] = true;
		}
		else if (maps[r][c] == 'F') {
			fq.push({ r, c });
			maps[r][c] = '#';
		}
	}

	int ret = 0;

	while (!jq.empty() || !fq.empty()) {
		int fsize = fq.size();
		while (fsize--) {
			auto pos = fq.front();
			fq.pop();

			for (int i = 0; i < 4; i++) {
				int nr = pos.first + dr[i];
				int nc = pos.second + dc[i];

				if (IsValid(nr, nc)) {
					maps[nr][nc] = 'F';
					fq.push({ nr, nc });
				}
			}
		}

		int jsize = jq.size();
		ret++;
		while (jsize--) {
			auto pos = jq.front();
			jq.pop();

			//cout << pos.first << ' ' << pos.second << '\n';

			for (int i = 0; i < 4; i++) {
				int nr = pos.first + dr[i];
				int nc = pos.second + dc[i];
				if (CanEscape(nr, nc)) {
					return ret;
				}
				else if (IsValid(nr, nc) && !visited[nr][nc]) {
					visited[nr][nc] = true;
					jq.push({ nr, nc });
				}
			}
		}




	}




	return -1;
}

void Solution() {
	int ret = Escape();
	//PrintVec(maps);
	if (ret == -1) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		cout << ret << '\n';
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