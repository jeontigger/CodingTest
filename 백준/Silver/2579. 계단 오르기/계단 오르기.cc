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
	vector<int> vec(N + 1);
	for (int i = 1; i < N + 1; i++) {
		cin >> vec[i];
	}
	vector<vector<int>> dp(N + 1, vector<int>(2));
	if (N == 1) {
		cout << vec[1];
		return 0;
	}

	dp[1][0] = vec[1];
	dp[1][1] = vec[1];

	dp[2][0] = dp[1][1] + vec[2];
	dp[2][1] = vec[2];

	for (int i = 3; i < N + 1; i++) {
		dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + vec[i];
		dp[i][0] = dp[i - 1][1] + vec[i];
	}

	cout << max(dp[N][0], dp[N][1]);
	//PrintVec(dp);


	return 0;
}
