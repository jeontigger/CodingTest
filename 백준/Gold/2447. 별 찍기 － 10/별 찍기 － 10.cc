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

void Stars(vector<vector<int>>& paper, int row, int col, int len) {

	if (len == 1) {
		paper[row][col] = 1;
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int div = len / 3;

			if (i == 1 && j == 1) continue;

			Stars(paper, row + div * i, col + div * j, div);
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> paper(N, vector<int>(N));

	Stars(paper, 0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (paper[i][j] == 1) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}