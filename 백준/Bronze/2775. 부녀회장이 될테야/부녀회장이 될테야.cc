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

	int n, t, k;
	cin >> t;



	for (int i = 0; i < t; i++) {
		cin >> k >> n;

		vector<int> dp(15);
		for (int j = 0; j < 15; j++) {
			dp[j] = j;
		}

		for (int j = 1; j <= k; j++) {
			for (int k = 1; k <= n; k++) {
				dp[k] = dp[k - 1] + dp[k];
			}
		}

		cout << dp[n] << endl;
	}


	return 0;
}