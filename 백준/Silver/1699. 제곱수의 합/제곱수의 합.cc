#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

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

int main() {
	int n;
	cin >> n;

	vector<int> dp(n + 1);

	for (int i = 0; i <= n; i++) {
		dp[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		long long sqr = pow(i, 2);
		for (long long j = sqr; j <= n; j++) {
			dp[j] = min(dp[j - sqr] + 1, dp[j]);
		}

		//PrintVec(dp);
	}

	cout << dp.back();

	return 0;
}