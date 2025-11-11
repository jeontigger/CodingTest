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

int N, minValue;
vector<int> num;
void Inputs() {
	cin >> N;

	minValue = INF;
	num.resize(N);
	FOR(i, N)
		cin >> num[i];
}


void Solution() {

	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
	vector<int> prefix(N + 1);
	for (int i = 1; i <= N; i++) {
		prefix[i] = prefix[i - 1] + num[i - 1];
	}

	//for (int i = 0; i < N; i++) {
	//	dp[i][i] = num[i];
	//}

	for (int len = 2; len <= N; ++len) {
		for (int i = 1; i + len - 1 <= N; ++i) {
			int j = i + len - 1;
			int best = INF;
			for (int k = i; k < j; ++k) {
				best = min(best, dp[i][k] + dp[k + 1][j]);
				//dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + prefix[j] - prefix[i - 1]);
			}
			dp[i][j] = best + (prefix[j] - prefix[i - 1]);
		}
	}
	cout << dp[1][N] << '\n';

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