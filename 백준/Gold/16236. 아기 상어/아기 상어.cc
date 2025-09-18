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

// 현재 위치에서 잡을 수 있는 물고기 있는지 검색
//
// 

int N;
int map[21][21];
pair<int, int> sharkPos;

void Inputs() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sharkPos = { i, j };
				map[i][j] = 0;
			}
		}
	}
}

struct PosData {
	int row;
	int col;
	int cnt;
};

struct cmp {
	bool operator()(const PosData& p1, const PosData& p2) {
		if (p1.cnt != p2.cnt) {
			return p1.cnt > p2.cnt;
		}
		else if (p1.row != p2.row) {
			return p1.row > p2.row;
		}
		else {
			return p1.col > p2.col;
		}
	}
};

int BFS(pair<int, int>& shark, int sharkSize) {

	int nrow[4] = { -1, 0, 0, 1 };
	int ncol[4] = { 0, -1, 1, 0 };

	int res = INF;
	priority_queue<PosData, vector<PosData>, cmp> pq;
	vector<vector<int>> visited(N, vector<int>(N));
	pq.push({ shark.first, shark.second, 0 });
	visited[shark.first][shark.second] = true;

	int cnt = -1;
	//pq.push({ 1, 1 });
	//pq.push({ 0, 1 });
	//pq.push({ 2, 3 });
	//auto pos = pq.top();

	while (!pq.empty()) {
		int size = pq.size();

		auto pos = pq.top();
		pq.pop();

		if (map[pos.row][pos.col] != 0 && map[pos.row][pos.col] < sharkSize) {
			shark = { pos.row, pos.col };
			map[pos.row][pos.col] = 0;
			//cout << pos.row << ' ' << pos.col << '\n';
			return pos.cnt;
		}

		for (int i = 0; i < 4; i++) {
			int _nrow = pos.row + nrow[i];
			int _ncol = pos.col + ncol[i];

			// 범위 조건
			if (0 <= _nrow && _nrow < N && 0 <= _ncol && _ncol < N) {
				// 방문 조건
				if (!visited[_nrow][_ncol]) {
					// 크기 조건
					if (sharkSize >= map[_nrow][_ncol]) {
						pq.push({ _nrow,_ncol, pos.cnt + 1 });
						visited[_nrow][_ncol] = true;
					}
				}
			}
		}

	}

	return res;
}

void Solution() {

	int curSize = 2;
	int curCnt = 0;
	int time = 0;
	while (true) {
		int res = BFS(sharkPos, curSize);
		if (res == INF) {
			break;
		}
		else {
			curCnt++;
			time += res;
			if (curCnt == curSize) {
				curSize++;
				curCnt = 0;
			}
		}
	}
	cout << time << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 1;
	//cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}