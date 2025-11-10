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

int N, K, c[100];
void Inputs() {
	cin >> N >> K;
	FOR(i, N)
		cin >> c[i];
}

void Solution() {
	// 카페인 양 = 커피 개수
	vector<int> dp(K + 1, INF);

	for (int i = 0; i < N; i++) {
		auto before = dp;
		dp[c[i]] = 1;
		for (int j = c[i]; j < dp.size(); j++) {
			if (before[j - c[i]] != INF) {
				dp[j] = min(before[j], before[j - c[i]] + 1);
			}
		}
	}
	if (K == 0)
		cout << 0;
	else if (dp[K] == INF)
		cout << -1;
	else
		cout << dp[K];
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