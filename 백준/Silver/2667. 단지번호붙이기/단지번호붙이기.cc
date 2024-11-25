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

int DFS(vector<vector<int>>& maps, int row, int col) {

	int res = 1;
	for (int i = 0; i < 4; i++) {
		int nrow = row + g_nrow[i];
		int ncol = col + g_ncol[i];

		if (0 <= nrow && nrow < maps.size() && 0 <= ncol && ncol < maps.size()) {
			if (maps[nrow][ncol] == 1) {
				maps[nrow][ncol] = 0;
				res += DFS(maps, nrow, ncol);
			}
		}
	}

	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> maps(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			maps[i][j] = c - '0';
		}
	}

	vector<int> res;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (maps[i][j] == 1) {
				maps[i][j] = 0;
				res.push_back(DFS(maps, i, j));
			}
		}
	}

	cout << res.size() << ' ';
	sort(res.begin(), res.end());
	PrintVec(res);

	return 0;
}