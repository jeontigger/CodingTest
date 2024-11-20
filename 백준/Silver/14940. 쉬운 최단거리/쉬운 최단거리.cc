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

struct Pos {
	int row;
	int col;
	int len = 0;
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N, vector<int>(M));

	Pos target;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 2) {
				target.row = i;
				target.col = j;
			}
		}
	}

	vector<vector<int>> newgraph(N, vector<int>(M));

	vector<vector<bool>> visited(N, vector<bool>(M));

	queue<Pos>q;
	q.push(target);
	visited[target.row][target.col] = true;

	int g_nrow[] = { 0, 1, 0, -1 };
	int g_ncol[] = { 1, 0, -1, 0 };

	while (!q.empty()) {
		Pos pos = q.front();
		q.pop();

		newgraph[pos.row][pos.col] = pos.len;

		for (int i = 0; i < 4; i++) {
			int nrow = pos.row + g_nrow[i];
			int ncol = pos.col + g_ncol[i];

			if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M) {
				if (visited[nrow][ncol]) continue;
				if (graph[nrow][ncol] == 0) continue;
				visited[nrow][ncol] = true;
				q.push({ nrow, ncol, graph[nrow][ncol] + pos.len });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 1 && newgraph[i][j] == 0) {
				newgraph[i][j] = -1;
			}
		}
	}

	PrintVec(newgraph);



	return 0;
}