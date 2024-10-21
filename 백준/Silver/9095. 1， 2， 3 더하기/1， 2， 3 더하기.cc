#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1e9


int main() {

	int n;
	cin >> n;
	vector<int> inputs(n);

	int maxNum = 0;
	for (int i = 0; i < n; i++) {
		cin >> inputs[i];
		maxNum = max(maxNum, inputs[i]);
	}

	vector<int> dp(maxNum + 1, 0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= maxNum; i++) {

		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int i = 0; i < n; i++) {
		cout << dp[inputs[i]] << endl;
	}


	return 0;
}