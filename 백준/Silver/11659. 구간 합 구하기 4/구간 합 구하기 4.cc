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
int nums[100001];

int c1[100001], c2[100001];

bool Inputs() {
	cin >> N >> M;
	FOR(i, N) {
		cin >> nums[i];
	}
	FOR(i, M) {
		cin >> c1[i] >> c2[i];
	}
	return true;
}

int pSum[100002];

void Init() {
	pSum[0] = 0;
	for (int i = 0; i < N; i++) {
		pSum[i+1] = pSum[i] + nums[i];
	}
}

void Solution() {
	Init();

	for (int i = 0; i < M; i++) {
		cout << pSum[c2[i]] - pSum[c1[i] - 1] << '\n';
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