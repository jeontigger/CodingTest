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

int GetWrongCnt(const vector<string>& board, int row, int col) {
	char LT = board[row][col];

	int res = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 != 0) {
				if (board[row + i][col + j] == LT) {
					res++;
				}
			}
			else {
				if (board[row + i][col + j] != LT) {
					res++;
				}
			}
		}
	}

	int other = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 != 0) {
				if (board[row + i][col + j] != LT) {
					other++;
				}
			}
			else {
				if (board[row + i][col + j] == LT) {
					other++;
				}
			}
		}
	}

	return min(res, other);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<string> board(N);
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}


	int minValue = 64;
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			// 좌상단 선택
			//cout << GetWrongCnt(board, i, j);
			//cout << i << " " << j << endl;
			minValue = min(GetWrongCnt(board, i, j), minValue);

		}
	}

	cout << minValue;

	return 0;
}