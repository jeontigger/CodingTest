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

	vector<int> dp(1001);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i < dp.size(); i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	//PrintVec(dp);
	int N;
	cin >> N;
	cout << dp[N];

	return 0;
}