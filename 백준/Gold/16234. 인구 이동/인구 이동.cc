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

// NxN의 땅. L이상 R 이하의 차이라면 연합
// 연합인구수 / 연합국. 소수점은 버림
// 날짜 수

// 모든 나라에 대해서 BFS
// BFS 되는 나라만 연합국
// 

int N, L, R;
int map[51][51];

void Inputs() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}

int Unite(int _row, int _col, vector<vector<int>>& visited) {
	int res = 1;
	queue<pair<int, int>> q;
	q.push({ _row, _col });
	visited[_row][_col] = true;

	int _nrow[4] = { 0, 1, 0, -1 };
	int _ncol[4] = { 1, 0, -1, 0 };

	vector<pair<int, int>> unions;
	int sum = map[_row][_col];
	unions.push_back({ _row, _col });

	while (!q.empty()) {
		auto pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nrow = pos.first + _nrow[i];
			int ncol = pos.second + _ncol[i];

			// 범위 조건
			if (0 <= nrow && nrow < N && 0 <= ncol && ncol < N) {
				// 중복 조건
				if (!visited[nrow][ncol]) {
					// LR 조건
					int cur = map[pos.first][pos.second];
					int next = map[nrow][ncol];
					int diff = abs(cur - next);
					if (L <= diff && diff <= R) {
						visited[nrow][ncol] = true;
						unions.push_back({ nrow, ncol });
						q.push({ nrow, ncol });
						res++;
						sum += map[nrow][ncol];
					}
				}
			}
		}
	}

	int people = sum / unions.size();
	for (int i = 0; i < unions.size(); i++) {
		auto pos = unions[i];
		map[pos.first][pos.second] = people;
	}

	if (unions.size() > 1) return res;
	return 0;
}

void Solution() {

	int day = 0;
	while (true) {
		int change = 0;
		vector<vector<int>> visited(N, vector<int>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					change += Unite(i, j, visited);
				}
			}
		}

		if (change == 0)
			break;

		day++;
	}

	cout << day;

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