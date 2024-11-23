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

int g_nhieght[] = { 0, 0, 0, 0, 1, -1 };
int g_nrow[] = { 1, 0, -1, 0, 0, 0 };
int g_ncol[] = { 0, 1, 0, -1, 0, 0 };

int M, N, H;
struct Pos {
	int height;
	int row;
	int col;
};

bool IsValid(int h, int r, int c, vector<vector<vector<int>>>& box) {
	if (h < 0 || h >= H) return false;
	if (r < 0 || r >= N) return false;
	if (c < 0 || c >= M) return false;

	if (box[h][r][c] == -1) return false;

	return true;
}

int CountingDay(vector<vector<vector<int>>>& box) {

	// 첫 익은 토마토 기입
	queue<Pos> q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[i][j][k] == 1) {
					box[i][j][k] = -1;
					q.push({ i, j, k });
				}
			}
		}
	}

	int cnt = -1;

	while (!q.empty()) {

		int size = q.size();
		cnt++;
		for (int j = 0; j < size; j++) {
			Pos pos = q.front();
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nheight = pos.height + g_nhieght[i];
				int nrow = pos.row + g_nrow[i];
				int ncol = pos.col + g_ncol[i];

				if (IsValid(nheight, nrow, ncol, box)) {
					box[nheight][nrow][ncol] = -1;
					q.push({ nheight, nrow, ncol });
				}
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[i][j][k] != -1) {
					return -1;
				}
			}
		}
	}

	return cnt;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> H;

	vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> box[i][j][k];
			}
		}
	}

	cout << CountingDay(box);



	return 0;
}