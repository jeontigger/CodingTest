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

int DFS(vector<vector<char>>& maps, int row, int col) {
	int res = 0;

	for (int i = 0; i < 4; i++) {
		int nrow = row + g_nrow[i];
		int ncol = col + g_ncol[i];

		if (0 <= nrow && nrow < maps.size() && 0 <= ncol && ncol < maps[0].size()) {
			if (maps[nrow][ncol] == 'O' || maps[nrow][ncol] == 'P') {
				if (maps[nrow][ncol] == 'P') {
					res++;
				}
				maps[nrow][ncol] = 'X';
				res += DFS(maps, nrow, ncol);
			}
		}
	}
	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<char>> maps(n, vector<char>(m));

	int row = 0, col = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 'I') {
				row = i;
				col = j;
			}
		}
	}

	int res = DFS(maps, row, col);
	res == 0 ? cout << "TT" : cout << res;

	return 0;
}