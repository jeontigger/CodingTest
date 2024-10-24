#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

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

struct Data {
	int blue = 0;
	int white = 0;

	void operator +=(const Data& d) {
		blue += d.blue;
		white += d.white;
	}
};

Data GetPaperArea(const vector<vector<int>>& paper, int startRow, int startCol, int len) {


	int firstColor = paper[startRow][startCol];

	Data res;
	firstColor == 1 ? res.blue = 1 : res.white = 1;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {

			// 색종이 내 다른 색 존재
			if (firstColor != paper[startRow + i][startCol + j]) {

				int half = len / 2;
				res.blue = 0;
				res.white = 0;

				// 좌상단
				res += GetPaperArea(paper, startRow, startCol, half);
				// 우상단
				res += GetPaperArea(paper, startRow, startCol + half, half);
				// 좌하단
				res += GetPaperArea(paper, startRow + half, startCol, half);
				// 우하단
				res += GetPaperArea(paper, startRow + half, startCol + half, half);

				return res;
			}
		}
	}

	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> paper(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	Data res = GetPaperArea(paper, 0, 0, N);

	cout << res.white << " " << res.blue;

	return 0;
}