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
	vector<int> dp(N + 1, INF);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 1; i < dp.size(); i++) {
		for (int j = i * i; j < dp.size(); j++) {
			dp[j] = min(dp[j], dp[j - i * i] + 1);
		}
	}

	cout << dp[N];


	return 0;
}