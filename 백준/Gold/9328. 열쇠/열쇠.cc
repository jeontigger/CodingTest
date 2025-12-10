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
#include <map>

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
vector<vector<int>> visited;
int keys[26];
vector<queue<pair<int, int>>> vecQ;
bool Inputs() {
	cin >> N >> M;
	maps.assign(N, vector<char>(M));
	visited.assign(N, vector<int>(M));
	vecQ.assign(26, queue<pair<int, int>>());
	memset(keys, 0, sizeof(keys));
	FOR(r, N)
		FOR(c, M)
		cin >> maps[r][c];

	string str;
	cin >> str;
	if (str != "0") {
		for (int i = 0; i < str.size(); i++) {
			keys[str[i] - 'a'] = 1;
		}
	}


	return true;
}

inline bool IsValid(int r, int c) {
	return !(r < 0 || r >= N || c < 0 || c >= M) && !visited[r][c] && maps[r][c] != '*';
}

inline bool IsKey(int r, int c) {
	return 'a' <= maps[r][c] && maps[r][c] <= 'z';
}

inline bool IsDoor(int r, int c) {
	return 'A' <= maps[r][c] && maps[r][c] <= 'Z';
}

inline bool IsPaper(int r, int c) {
	return maps[r][c] == '$';
}

int BFS(int r, int c) {
	// 문을 만나면 vecQ에 추가
	// 문서를 만나면 ret++
	// 열쇠를 만나면 keys에 체크

	int ret = 0;
	queue<pair<int, int>> q;
	if (IsDoor(r, c)) {
		vecQ[maps[r][c] - 'A'].push({ r, c });
		visited[r][c] = true;
		return 0;
	}
	else if (IsKey(r, c)) {
		keys[maps[r][c] - 'a'] = 1;
	}
	else if (IsPaper(r, c)) {
		ret++;
	}
	q.push({ r, c });
	visited[r][c] = true;

	while (!q.empty()) {
		auto pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = pos.first + dr[i];
			int nc = pos.second + dc[i];

			if (IsValid(nr, nc)) {
				if (IsDoor(nr, nc)) {
					vecQ[maps[nr][nc] - 'A'].push({ nr, nc });
					visited[nr][nc] = true;
					continue;
				}
				else if (IsKey(nr, nc)) {
					keys[maps[nr][nc] - 'a'] = 1;
				}
				else if (IsPaper(nr, nc)) {
					ret++;
				}
				q.push({ nr, nc });
				visited[nr][nc] = true;
			}
		}
	}

	return ret;
}

int Init() {
	int ret = 0;
	FOR(r, N) {
		if (IsValid(r, 0)) {
			ret += BFS(r, 0);
		}
		if (IsValid(r, M - 1)) {
			ret += BFS(r, M - 1);
		}
	}

	FOR(c, M) {
		if (IsValid(0, c)) {
			ret += BFS(0, c);
		}

		if (IsValid(N - 1, c)) {
			ret += BFS(N - 1, c);
		}
	}

	return ret;
}

int BFS(queue<pair<int, int>>& q) {
	int ret = 0;

	while (!q.empty()) {
		auto pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = pos.first + dr[i];
			int nc = pos.second + dc[i];

			if (IsValid(nr, nc)) {
				if (IsDoor(nr, nc)) {
					vecQ[maps[nr][nc] - 'A'].push({ nr, nc });
					visited[nr][nc] = 1;
					continue;
				}
				else if (IsKey(nr, nc)) {
					keys[maps[nr][nc] - 'a'] = 1;
				}
				else if (IsPaper(nr, nc)) {
					ret++;
				}
				q.push({ nr, nc });
				visited[nr][nc] = true;
			}
		}
	}

	return ret;
}

void Solution() {
	int ret = 0;
	ret += Init();

	int tmp = -1;
	while (tmp != 0) {
		tmp = 0;
		for (int i = 0; i < vecQ.size(); i++) {
			if (keys[i] && !vecQ[i].empty()) {
				ret += BFS(vecQ[i]);
				tmp++;
			}
		}
	}

	cout << ret << '\n';
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