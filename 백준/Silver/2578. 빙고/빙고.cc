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
#include <map>

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

int maps[5][5];
int nums[25];
int rows[5], cols[5], ltrb, rtlb;
unordered_map<int, pair<int, int>> numPos;

bool Inputs() {
	FOR(i, 5)
		FOR(j, 5) {
		cin >> maps[i][j];
		numPos[maps[i][j]] = { i, j };
	}

	FOR(i, 25)
		cin >> nums[i];

	memset(rows, 0, sizeof(rows));
	memset(cols, 0, sizeof(cols));
	ltrb = rtlb = 0;
	return true;
}

bool IsBingo() {
	int cnt = 0;
	FOR(i, 5) {
		cnt += rows[i] == 5;
		cnt += cols[i] == 5;
	}
	cnt += ltrb == 5;
	cnt += rtlb == 5;

	return cnt >= 3;
}

void Check(int r, int c) {
	rows[r]++;
	cols[c]++;
	if (r == c) ltrb++;
	if (r == 4 - c) rtlb++;
}

void Solution() {
	int cnt = 0;
	for (; cnt < 25; cnt++) {
		auto pos = numPos[nums[cnt]];
		//cout << nums[cnt] << ' ';
		Check(pos.first, pos.second);
		if (IsBingo()) break;
	}

	cout << cnt + 1 << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 1;
	//cin >> T;
	while (T--) {
		if (!Inputs()) break;
		Solution();
	}

	return 0;
}