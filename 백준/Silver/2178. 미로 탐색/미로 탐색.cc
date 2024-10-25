#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

#define INF 1e9

template<typename T>
void PrintVec(const vector<T>& v) {
	for (T i : v) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T>
void PrintVec(const vector<vector<T>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

struct Pos {
	int row;
	int col;
	int cnt;
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> maps(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			maps[i][j] = c - '0';
		}
	}

	queue<Pos> q;
	q.push({ 0, 0, 1 });

	while (!q.empty()) {
		Pos pos = q.front();
		q.pop();

		if (pos.row == N - 1 && pos.col == M - 1) {
			cout << pos.cnt;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nrow = pos.row + g_nrow[i];
			int ncol = pos.col + g_ncol[i];

			if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M) {
				if (maps[nrow][ncol] == 1) {
					maps[nrow][ncol] = 0;
					q.push({ nrow, ncol, pos.cnt + 1 });
				}
			}
		}
	}



	return 0;
}