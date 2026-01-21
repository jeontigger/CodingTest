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

int N, M, K;
int nums[301][301], sum[302][302];
int xs[10001], ys[10001], xe[10001], ye[10001];

bool Inputs() {
	cin >> N >> M;
	FOR(i, N)
		FOR(j, M)
		cin >> nums[i][j];

	cin >> K;
	FOR(i, K)
		cin >> ys[i] >> xs[i] >> ye[i] >> xe[i];

	return true;
}

void Init() {
	for (int i = 0; i < N; i++) {
		sum[i][0] = 0;
		for (int j = 0; j < M; j++) {
			sum[i][j + 1] = sum[i][j] + nums[i][j];
		}
	}
}

int GetSum(int ys, int xs, int ye, int xe) {
	int ret = 0;

	for (int y = ys; y <= ye; y++) {
		ret += sum[y - 1][xe] - sum[y - 1][xs - 1];
	}

	return ret;
}

void Solution() {
	Init();

	for (int i = 0; i < K; i++) {
		cout << GetSum(ys[i], xs[i], ye[i], xe[i]) << '\n';
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