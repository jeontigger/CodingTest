#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <set>

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

int g_row[] = { 0, 1, 0, -1 };
int g_col[] = { 1, 0, -1, 0 };

int id = 1;

int DFS(vector<vector<int>>& blanks, int row, int col) {

	int resSum = 1;
	for (int i = 0; i < 4; i++) {
		int nrow = row + g_row[i];
		int ncol = col + g_col[i];

		if (0 <= nrow && nrow < blanks.size() && 0 <= ncol && ncol < blanks[0].size()) {
			if (blanks[nrow][ncol] == 0) {
				blanks[nrow][ncol] = id;
				resSum += DFS(blanks, nrow, ncol);
			}
		}
	}

	return resSum;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<string> maps(N);
	for (int i = 0; i < N; i++) {
		cin >> maps[i];
	}

	vector<vector<int>>blanks(N);

	for (int i = 0; i < N; i++) {
		blanks[i].resize(M);
		for (int j = 0; j < M; j++) {
			if (maps[i][j] != '0') {
				blanks[i][j] = -1;
			}
		}
	}

	vector<int> groups;
	groups.push_back(0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (blanks[i][j] == 0) {
				blanks[i][j] = id;
				int res = DFS(blanks, i, j);
				groups.push_back(res);
				id++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (maps[i][j] == '1') {
				vector<bool> visited(id + 1);
				int sum = 0;
				for (int k = 0; k < 4; k++) {
					int nrow = i + g_row[k];
					int ncol = j + g_col[k];

					if (0 <= nrow && nrow < blanks.size() && 0 <= ncol && ncol < blanks[0].size()) {
						if (blanks[nrow][ncol] != -1 && !visited[blanks[nrow][ncol]]) {
							visited[blanks[nrow][ncol]] = true;
							sum += groups[blanks[nrow][ncol]];
						}
					}
				}
				maps[i][j] = (sum + 1) % 10 + '0';
			}
		}
	}

	PrintVec(maps);

	return 0;
}