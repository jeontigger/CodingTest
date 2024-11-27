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

struct Pos {
	int row;
	int col;
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> maps(n, vector<int>(m));

	Pos start;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 2) {
				start.row = i;
				start.col = j;
			}
		}
	}

	queue<Pos> q;
	q.push(start);

	vector<vector<bool>> visited(n, vector<bool>(m));
	visited[start.row][start.col] = true;
	int g_nrow[] = { 0, 1, 0, -1 };
	int g_ncol[] = { 1, 0, -1, 0 };
	maps[start.row][start.col] = 0;

	while (!q.empty()) {
		Pos curPos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nrow = curPos.row + g_nrow[i];
			int ncol = curPos.col + g_ncol[i];

			if (0 <= nrow && nrow < n && 0 <= ncol && ncol < m) {
				if (visited[nrow][ncol] || maps[nrow][ncol] == 0) continue;
				maps[nrow][ncol] += maps[curPos.row][curPos.col];
				visited[nrow][ncol] = true;
				q.push({ nrow, ncol });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || maps[i][j] == 0) continue;
			maps[i][j] = -1;
		}
	}

	PrintVec(maps);


	return 0;
}