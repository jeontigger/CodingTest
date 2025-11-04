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

int n, k;
int val[101];

void Inputs() {
	cin >> n >> k;
	FOR(i, n)
		cin >> val[i];
}

void Solution() {
	vector<int> dp(10001, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		dp[val[i]] = 1;
		for (int j = val[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - val[i]] + 1);
		}
	}
	if (dp[k] == INF)
		cout << -1 << '\n';
	else
		cout << dp[k] << '\n';
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