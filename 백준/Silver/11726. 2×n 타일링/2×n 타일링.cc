#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1e9

void PrintVec(const vector<int>& v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {

	int n;
	cin >> n;

	vector<int> dp(n);

	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; i < n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}

	cout << dp[n - 1];

	return 0;
}