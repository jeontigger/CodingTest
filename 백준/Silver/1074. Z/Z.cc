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

void Z(int row, int col, int trow, int tcol, int size, int value) {
	//cout << row << " " << col << " " << value << endl;
	if (size == 1) {
		cout << value;
		return;
	}

	int half = size / 2;
	int quat = pow(half, 2);

	if ((trow - row) / half) value += quat * 2;
	if ((tcol - col) / half) value += quat;
	Z(row + (trow - row) / half * half, col + (tcol - col) / half * half, trow, tcol, half, value);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, r, c;
	cin >> N >> r >> c;

	int target = pow(2, N);

	Z(0, 0, r, c, target, 0);

	//cout << g_cnt;
	return 0;
}