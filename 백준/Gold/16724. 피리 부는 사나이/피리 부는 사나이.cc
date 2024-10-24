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
int g_dir[] = { 'R', 'D', 'L', 'U' };
int g_rdir[] = { 'L', 'U', 'R', 'D' };

void DFS(vector<vector<char>>& maps, vector<vector<bool>>& visited, int row, int col) {

	for (int i = 0; i < 4; i++) {
		int nrow = row + g_nrow[i];
		int ncol = col + g_ncol[i];

		if (0 <= nrow && nrow < maps.size() && 0 <= ncol && ncol < maps[0].size()) {
			if (maps[row][col] == g_dir[i] || maps[nrow][ncol] == g_rdir[i]) {
				if (visited[nrow][ncol]) continue;
				visited[nrow][ncol] = true;
				DFS(maps, visited, nrow, ncol);
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<char>> maps(n, vector<char>(m));
	vector<vector<bool>> visited(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maps[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				DFS(maps, visited, i, j);
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}