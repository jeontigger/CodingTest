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
#include <iomanip>
#include <cassert>
#include <cstring>
#include <list>

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
#define FOR(idx, limit) for(int idx = 0; idx < limit; idx++)

int N, K;
int in[10000], t[10000];

void Inputs() {
	cin >> N >> K;
	FOR(i, K)
		cin >> in[i] >> t[i];
}

void Solution() {
	vector<int> dp(10001);

	for (int i = 0; i < K; i++) {
		auto before = dp;
		for (int j = t[i]; j < dp.size(); j++) {
			dp[j] = max(before[j], before[j - t[i]] + in[i]);
		}
	}

	cout << dp[N];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	//cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}