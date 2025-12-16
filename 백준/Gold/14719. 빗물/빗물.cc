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

int H, W;
int maps[500][500];
bool Inputs() {
	cin >> H >> W;
	vector<int> nums(W);
	FOR(n, W)
		cin >> nums[n];

	// 맵 구성
	for (int i = 0; i < W; i++) {
		int r = 0;

		// 블록 세우기
		for (; r < nums[i]; r++) {
			maps[r][i] = 1;
		}

		// 빗물 집어넣기
		for (; r < H; r++) {
			maps[r][i] = 2;
		}
	}

	// 출력 체크
	/*FOR(r, H) {
		FOR(c, W)
			cout << maps[r][c] << ' ';
		cout << '\n';
	}*/

	return true;
}

void RemoveRain(int r, int c, int delta) {
	for (int i = 0; i < W; i++) {
		if (maps[r][c] != 2) break;
		maps[r][c] = 0;
		c += delta;
	}
}

int CountRain() {
	int ret = 0;
	FOR(r, H) {
		FOR(c, W) {
			if (maps[r][c] == 2) ret++;
		}
	}
	return ret;
}

void Solution() {
	for (int r = 0; r < H; r++) {
		// 빗물 제거
		if (maps[r][0] == 2) {
			RemoveRain(r, 0, 1);
		}

		if (maps[r][W - 1] == 2) {
			RemoveRain(r, W - 1, -1);
		}
	}
	cout << CountRain() << '\n';
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