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

	vector<int> dp(40001);
	int N;
	cin >> N;
	vector<int> weights(N);
	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		weights[i] = n;
		//dp[n] = true;
	}

	dp[0] = 1;
	for (int i = 0; i < weights.size(); i++) {
		auto pdp = dp;
		for (int j = 0; j < dp.size(); j++) {
			if (j - weights[i] >= 0 && pdp[j - weights[i]]) {
				dp[j] = true;
			}
		}
	}
	for (int i = 0; i < weights.size(); i++) {
		auto pdp = dp;
		for (int j = 0; j < dp.size(); j++) {
			if (j + weights[i] < dp.size() && pdp[j + weights[i]]) {
				dp[j] = true;
			}
		}
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		if (dp[n]) {
			cout << "Y ";
		}
		else {
			cout << "N ";
		}
	}
	return 0;
}