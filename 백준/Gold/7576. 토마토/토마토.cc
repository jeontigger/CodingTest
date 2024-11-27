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

	int M, N;
	cin >> M >> N;

	vector<vector<int>> maps(N, vector<int>(M));
	queue<Pos> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}

	int g_nrow[] = { 0, 1, 0, -1 };
	int g_ncol[] = { 1, 0, -1, 0 };

	int cnt = -1;
	while (!q.empty()) {
		cnt++;
		int size = q.size();
		while (size--) {
			Pos curPos = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nrow = curPos.row + g_nrow[i];
				int ncol = curPos.col + g_ncol[i];

				if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M) {
					if (maps[nrow][ncol] == 0) {
						maps[nrow][ncol] = 1;
						q.push({ nrow, ncol });
					}
				}
			}
		}

	}


	bool bFail = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (maps[i][j] == 0) {
				bFail = true;
				break;
			}
		}
		if (bFail) break;
	}

	if (bFail) {
		cout << -1 << ' ';
	}
	else {
		cout << cnt << ' ';
	}


	return 0;
}