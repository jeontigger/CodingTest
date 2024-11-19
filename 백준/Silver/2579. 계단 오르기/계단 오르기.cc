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
	cout << endl;
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

	vector<vector<int>> dp(N, vector<int>(2));
	vector<int> steps(N);
	for (int i = 0; i < N; i++) {
		cin >> steps[i];
	}

	if (N == 1) {
		cout << steps[0];
		return 0;
	}

	dp[0][0] = steps[0];
	dp[0][1] = steps[0];
	dp[1][0] = steps[1] + steps[0];
	dp[1][1] = steps[1];

	for (int i = 2; i < dp.size(); i++) {
		dp[i][0] = dp[i - 1][1] + steps[i];
		dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + steps[i];
	}

	cout << *max_element(dp.back().begin(), dp.back().end());

	return 0;
}