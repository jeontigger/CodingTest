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

vector<int> visited(26);

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

int DFS(const vector<vector<char>>& maps, int row, int col) {
	int res = 0;

	for (int i = 0; i < 4; i++) {
		int nrow = row + g_nrow[i];
		int ncol = col + g_ncol[i];

		if (0 <= nrow && nrow < maps.size() && 0 <= ncol && ncol < maps[0].size()) {
			char alpha = maps[nrow][ncol] - 'A';
			if (!visited[alpha]) {
				visited[alpha] = true;
				res = max(res, 1 + DFS(maps, nrow, ncol));
				visited[alpha] = false;
			}
		}
	}
	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector < vector<char>> maps(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
		}
	}

	visited[maps[0][0] - 'A'] = true;
	cout << DFS(maps, 0, 0) + 1;


	return 0;
}
