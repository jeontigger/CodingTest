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

int N, C[5000], P[5000];
int M;

void Inputs() {
	float m;
	cin >> N >> m;
	M = round(m * 100);
	if (N == 0 && M == 0) exit(0);
	FOR(i, N) {
		int c;
		float p;
		cin >> c >> p;
		C[i] = c;
		P[i] = round(p * 100);
	}
}

void Solution() {
	// [돈] = 최대 칼로리

	vector<int> dp(10001, 0);
	for (int i = 0; i < N; i++) {
		for (int j = P[i]; j < dp.size(); j++) {
			dp[j] = max(dp[j], dp[j - P[i]] + C[i]);
		}
	}

	cout << dp[M] << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	//cin >> T;
	while (true) {
		Inputs();
		Solution();
	}


	return 0;
}