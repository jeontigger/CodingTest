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

int N, M, D;
vector<vector<char>> maps;
vector<vector<int>> dist;
vector<pair<int, int>> poses;
map<pair<int, int>, int> idxs;
int roboIdx = -1;
int minValue = INF;

// [방문한 노드 bitmask][현재 노드]
int cache[2049][12];

bool Inputs() {
	cin >> M >> N;
	if (M == 0 || N == 0)return false;
	maps.assign(N, vector<char>(M));
	poses.clear();
	dist.clear();
	idxs.clear();
	memset(cache, -1, sizeof(cache));
	minValue = INF;

	FOR(r, N)
		FOR(c, M) {
		cin >> maps[r][c];
		if (maps[r][c] == 'o' || maps[r][c] == '*') {
			if (maps[r][c] == 'o') {
				roboIdx = poses.size();
			}
			idxs[{r, c}] = poses.size();
			poses.push_back({ r, c });
		}
	}
	D = poses.size();
	dist.resize(D, vector<int>(D, INF));

	return true;
}

inline bool IsValid(int r, int c, const vector<vector<int>>& visited) {
	return !(r < 0 || r >= N || c < 0 || c >= M) && !visited[r][c] && maps[r][c] != 'x';
}

void BFS(int n) {
	dist[n][n] = 0;
	queue<pair<int, int>> q;
	q.push(poses[n]);
	vector<vector<int>> visited(N, vector<int>(M));
	visited[poses[n].first][poses[n].second] = true;

	int step = 0;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			auto node = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nr = node.first + dr[i];
				int nc = node.second + dc[i];

				if (IsValid(nr, nc, visited)) {
					visited[nr][nc] = true;
					q.push({ nr, nc });
					if (maps[nr][nc] == '*' || maps[nr][nc] == 'o') {
						dist[n][idxs[{nr, nc}]] = step + 1;
					}
				}
			}
		}
		step++;
	}
}

int DFS(int path, int idx) {
	int& ret = cache[path][idx];
	if (ret != -1) return ret;
	if (path == pow(2, D) - 1) {
		return ret = 0;
	}
	ret = INF;

	for (int i = 0; i < D; i++) {
		if ((path & (1 << i)) == 0) {
			ret = min(ret, DFS(path | (1 << i), i) + dist[idx][i]);
		}
	}

	return ret;
}

void Solution() {
	// 그리디 아님. 
	// 로청 위치를 포함한 더러운 부분들을 가야하는 정점이라고 생각함
	// 모든 정점에서 모든 정점을 가는 최소치를 찾음
	// 로청 row에서 못가는 영역 있으면 -1
	// 그 다음 순회해서 제일 작은 값

	// 로청과 다른 더러운 곳 정점간의 거리 찾기
	BFS(roboIdx);

	// 하나라도 못가면 -1
	for (int i = 0; i < D; i++) {
		if (dist[roboIdx][i] == INF) {
			cout << -1 << '\n';
			return;
		}
	}

	// 모든 정점에서 모든 정점으로 가는 거리 찾기
	for (int i = 0; i < D; i++) {
		if (i == roboIdx)continue;
		BFS(i);
	}


	cout << DFS(1 << roboIdx, roboIdx) << '\n';

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//int T = 1;
	//cin >> T;
	while (true) {
		if (!Inputs()) break;
		Solution();
	}

	return 0;
}