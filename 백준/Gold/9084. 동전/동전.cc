#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

#define INF 1e9


void PrintVec(const vector<int>& v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

void PrintVec(const vector<vector<int>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

void Solution(int N, int M, vector<int>& coins, vector<int>& dp) {
	for (int i = 0; i < N; i++) {
		dp[coins[i]]++;
		for (int j = coins[i]; j <= M; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}

	cout << dp[M] << endl;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, M;
	cin >> T;

	vector<int> dp(10001);

	for (int i = 0; i < T; i++) {
		// input
		cin >> N;
		vector<int> coins(N);
		for (int j = 0; j < N; j++) {
			cin >> coins[j];
		}

		cin >> M;

		// solution
		for (int i = 0; i < dp.size(); i++) {
			dp[i] = 0;
		}
		Solution(N, M, coins, dp);
	}


	return 0;
}