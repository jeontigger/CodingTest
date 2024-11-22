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
vector<vector<char>> maps;
struct Pos {
	int row;
	int col;
};

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

int BFS(Pos start) {
	int res = 0;

	queue<Pos> q;
	q.push(start);
	maps[start.row][start.col] = 'X';
	while (!q.empty()) {
		Pos curPos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nrow = curPos.row + g_nrow[i];
			int ncol = curPos.col + g_ncol[i];

			if (0 <= nrow && nrow < maps.size() && 0 <= ncol && ncol < maps[0].size()) {
				if (maps[nrow][ncol] == 'X')continue;

				if (maps[nrow][ncol] == 'P') res++;

				q.push({ nrow, ncol });
				maps[nrow][ncol] = 'X';
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
	maps.resize(N, vector<char>(M));

	Pos start;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 'I') {
				start.row = i;
				start.col = j;
			}
		}
	}

	//PrintVec(maps);

	int res = BFS(start);
	if (res == 0) {
		cout << "TT";
	}
	else {
		cout << res;
	}


	return 0;
}