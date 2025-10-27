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
#include <list>

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
#define FOR(idx, limit) for(int idx = 0; idx < limit; idx++)

// 2차원을 주고 쿼드트리로 1차원으로 압축해라
// N은 2의 제곱수로 주어지며, 1<= N <= 64, 데이터가 0과 1로 들어옴

int N;
string board[64];

void Inputs() {
	cin >> N;
	FOR(i, N) {
		cin >> board[i];
	}
}

bool AllSame(int row, int col, int size) {
	char sample = board[row][col];

	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (sample != board[i][j]) {
				return false;
			}
		}
	}

	return true;
}

string DC(int row, int col, int size) {
	if (size == 1) return to_string(board[row][col] - '0');

	string ret = "(";
	// 모두 같을경우
	if (AllSame(row, col, size)) return to_string(board[row][col] - '0');

	// 분할
	int half = size / 2;
	ret += DC(row, col, half);
	ret += DC(row, col + half, half);
	ret += DC(row + half, col, half);
	ret += DC(row + half, col + half, half);

	ret += ")";
	return ret;
}

void Solution() {

	cout << DC(0, 0, N);
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