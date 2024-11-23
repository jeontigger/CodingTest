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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> dp(N);
	cin >> dp[0];
	for (int i = 1; i < N; i++) {
		auto pdp = dp;
		int n;
		cin >> n;
		dp[0] = pdp[0] + n;
		for (int j = 1; j < i; j++) {
			cin >> n;
			dp[j] = max(pdp[j], pdp[j - 1]) + n;
		}
		cin >> n;
		dp[i] = pdp[i - 1] + n;

		//PrintVec(dp);
	}

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}