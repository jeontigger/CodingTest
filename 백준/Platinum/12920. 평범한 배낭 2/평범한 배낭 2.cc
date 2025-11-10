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

int N, M, V[100], C[100], K[100];
// 무게(V), 만족도(C), 개수(K)

void Inputs() {
	cin >> N >> M;
	FOR(i, N)
		cin >> V[i] >> C[i] >> K[i];
}

void Init(vector<int>& w, vector<int>& c) {
	for (int i = 0; i < N; i++) {
		for (int j = 1; K[i] > 0; j <<= 1) {
			int n = min(j, K[i]);
			w.push_back(V[i] * n);
			c.push_back(C[i] * n);
			K[i] -= n;
		}
	}
}

void Solution() {
	vector<int> w;
	vector<int> c;
	Init(w, c);


	// [무게] = 만족도
	vector<int> dp(20001, 0);
	dp[0] = 0;

	for (int i = 0; i < w.size(); i++) {
		auto before = dp;
		for (int j = w[i]; j < dp.size(); j++) {
			dp[j] = max(dp[j], before[j - w[i]] + c[i]);
		}
	}

	cout << dp[M];

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