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

int N;
int r[100], c[100];
int paper[100][100];

void Inputs() {
	cin >> N;
	FOR(i, N) {
		cin >> r[i] >> c[i];
	}
}

void Painting(int row, int col) {
	for (int i = row; i < 10 + row; i++) {
		for (int j = col; j < col + 10; j++) {
			paper[i][j]++;
		}
	}
}

int CalcBlackArea() {
	int ret = 0;

	FOR(i, 100)
		FOR(j, 100) {
		if (paper[i][j] != 0) ret++;
	}

	return ret;
}

void Solution() {
	for (int i = 0; i < N; i++) {
		Painting(r[i], c[i]);
	}
	int area = CalcBlackArea();
	cout << area;

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