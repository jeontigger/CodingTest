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

int N, M;
int nums[1025][1025], sum[1026][1026];
int xs[100001], xe[100001], ys[100001], ye[100001];

bool Inputs() {
	cin >> N >> M;
	FOR(i, N) {
		FOR(j, N) {
			cin >> nums[i][j];
		}
	}

	FOR(i, M) {
		cin >> xs[i] >> ys[i] >> xe[i] >> ye[i];
	}

	return true;
}

void Init() {
	for (int i = 0; i < N; i++) {
		sum[i][0] = 0;
		for (int j = 0; j < N; j++) {
			sum[i][j + 1] = sum[i][j] + nums[i][j];
		}
	}
}

int GetSum(int _xs, int _ys, int _xe, int _ye) {
	int ret = 0;
	for (int x = _xs; x <= _xe; x++) {
		ret += sum[x-1][_ye] - sum[x-1][_ys-1];
	}
	return ret;
}

void Solution() {
	Init();

	for (int i = 0; i < M; i++) {
		cout << GetSum(xs[i], ys[i], xe[i], ye[i]) << '\n';
	}
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