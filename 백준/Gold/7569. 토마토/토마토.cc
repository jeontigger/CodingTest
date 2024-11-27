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
	int height;
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N, H;
	cin >> M >> N >> H;

	vector<vector<vector<int>>> maps(H, vector<vector<int>>(N, vector<int>(M)));
	queue<Pos> q;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> maps[k][i][j];
				if (maps[k][i][j] == 1) {
					q.push({ i, j, k });
				}
			}
		}
	}

	int g_nheight[] = { 0, 0, 0, 0, 1, -1 };
	int g_nrow[] = { 0, 1, 0, -1, 0, 0 };
	int g_ncol[] = { 1, 0, -1, 0 , 0, 0 };

	int cnt = -1;
	while (!q.empty()) {
		cnt++;
		int size = q.size();
		while (size--) {
			Pos curPos = q.front();
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nheight = curPos.height + g_nheight[i];
				int nrow = curPos.row + g_nrow[i];
				int ncol = curPos.col + g_ncol[i];

				if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M && 0 <= nheight && nheight < H) {
					if (maps[nheight][nrow][ncol] == 0) {
						maps[nheight][nrow][ncol] = 1;
						q.push({ nrow, ncol, nheight });
					}
				}
			}
		}
	}

	bool bFail = false;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (maps[k][i][j] == 0) {
					bFail = true;
					break;
				}
			}
			if (bFail) break;
		}
	}

	if (bFail) {
		cout << -1 << ' ';
	}
	else {
		cout << cnt << ' ';
	}


	return 0;
}