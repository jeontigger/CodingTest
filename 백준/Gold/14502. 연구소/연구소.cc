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

int N, M;
vector<vector<int>> maps;

bool BuildWall(int num) {
	int row = num / M;
	int col = num % M;
	if (maps[row][col] != 0) return false;
	maps[row][col] = 1;

	return true;
}

void CancelWall(int num) {
	int row = num / M;
	int col = num % M;

	maps[row][col] = 0;
}

struct Pos {
	int row;
	int col;
};

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

bool VirusValid(int row, int col, const vector<vector<int>>& maps) {
	if (row < 0 || row >= N) return false;
	if (col < 0 || col >= M) return false;

	if (maps[row][col] != 0) return false;

	return true;
}

void Virus(vector<vector<int>>& testMaps) {
	queue<Pos> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (testMaps[i][j] == 2) {
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		Pos pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nrow = pos.row + g_nrow[i];
			int ncol = pos.col + g_ncol[i];

			if (VirusValid(nrow, ncol, testMaps)) {
				testMaps[nrow][ncol] = 2;
				q.push({ nrow, ncol });
			}
		}
	}
}

int Check(vector<vector<int>>& testMaps) {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (testMaps[i][j] == 0) {
				res++;
			}
		}
	}
	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	maps.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
		}
	}

	// 벽세우기
	// 검사하기

	int row, col;
	int maxValue = 0;
	for (int i = 0; i < N * M; i++) {
		if (!BuildWall(i)) continue;

		for (int j = i + 1; j < N * M; j++) {
			if (!BuildWall(j)) continue;

			for (int k = j + 1; k < N * M; k++) {
				if (!BuildWall(k)) continue;

				// 바이러스 퍼지기
				auto testMap = maps;
				Virus(testMap);
				// 검사하기
				maxValue = max(maxValue, Check(testMap));

				CancelWall(k);
			}
			CancelWall(j);
		}
		CancelWall(i);
	}

	cout << maxValue;



	return 0;
}
