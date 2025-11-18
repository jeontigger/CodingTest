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

int N, M, coins[20];

void Inputs() {
	cin >> N;
	FOR(i, N) {
		cin >> coins[i];
	}
	cin >> M;
}

void Solution() {
	vector<int> dp(M + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < N; i++) {
		int coin = coins[i];
		for (int j = coin; j < dp.size(); j++) {
			dp[j] += dp[j - coin];
		}

	}

	cout << dp[M] << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}