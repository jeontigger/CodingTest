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
#include <iomanip>
#include <cassert>
#include <cstring>

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

// N은 세로, M은 가로
// 칸의 수는 높이를 뜻함
// 계속 내려가고만 싶고, 내려가는 경우의 수에 대해 세고 싶음
// 시작점은 좌상단, 끝점은 우하단

int N, M;
int maps[501][501];
int cache[501][501];
int Case = 0;
void Inputs() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
		}
	}

	memset(cache, -1, sizeof(cache));
}

int DFS(int row, int col) {
	if (row == N - 1 && col == M - 1) {
		return 1;
	}
	int& ret = cache[row][col];
	if (ret != -1) return ret;

	int drow[4] = { 0, 1, 0, -1 };
	int dcol[4] = { 1, 0, -1 , 0 };

	ret = 0;
	for (int i = 0; i < 4; i++) {
		int nrow = row + drow[i];
		int ncol = col + dcol[i];
		// 범위 예외
		if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M) {
			//내리막
			if (maps[nrow][ncol] < maps[row][col]) {
				ret += DFS(nrow, ncol);
			}
		}
	}

	return ret;
}

void Solution() {

	DFS(0, 0);
	cout << cache[0][0] << '\n';

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << cache[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 1;
	//cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}