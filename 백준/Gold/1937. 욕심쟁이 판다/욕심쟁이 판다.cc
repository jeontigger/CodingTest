#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

#define INF 1e9


void PrintVec(const vector<int>& v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

void PrintVec(const vector<vector<int>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };
int g_maxValue = 0;
int DFS(const vector<vector<int>>& maps, int row, int col, vector<vector<int>>& dp) {
	if (dp[row][col] != 0) return dp[row][col];

	int n = maps.size();

	for (int i = 0; i < 4; i++) {
		int nrow = row + g_nrow[i];
		int ncol = col + g_ncol[i];

		int depth = 1;
		if (0 <= nrow && nrow < n && 0 <= ncol && ncol < n) {
			if (maps[row][col] < maps[nrow][ncol]) {
				depth += DFS(maps, nrow, ncol, dp);
			}
		}

		dp[row][col] = max(dp[row][col], depth);
		g_maxValue = max(g_maxValue, dp[row][col]);
	}

	return dp[row][col];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> maps(n, vector<int>(n));
	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maps[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			DFS(maps, i, j, dp);
		}
	}

	cout << g_maxValue;

	return 0;
}