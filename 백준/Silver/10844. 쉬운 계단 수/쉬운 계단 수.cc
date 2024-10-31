#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

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

	vector<int> dp(10);

	// 10, 12, 98
	for (int i = 1; i < 10; i++) {
		dp[i] = 1;
	}

	for (int i = 1; i < N; i++) {
		vector<int> origin = dp;
		dp[0] = origin[1];
		for (int j = 1; j < 9; j++) {
			dp[j] = (origin[j - 1] + origin[j + 1]) % 1000000000;
		}
		dp[9] = origin[8];
	}

	int sum = 0;
	for (int i : dp) {
		sum = (sum + i) % 1000000000;
	}

	cout << sum << endl;

	return 0;
}