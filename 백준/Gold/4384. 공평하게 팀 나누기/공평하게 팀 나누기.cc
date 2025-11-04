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

int N;
int w[101];

void Inputs() {
	cin >> N;
	FOR(i, N)
		cin >> w[i];
}

void Solution() {
	// N이 홀수면 사람 수 1차이 날것이고, 짝수면 차이 x
	vector<vector<int>> dp(N + 1, vector<int>(450 * 100 + 1));
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		int weight = w[i];
		for (int j = N; j >= 1; j--) {
			for (int k = 45000; k >= weight; k--) {
				dp[j][k] |= dp[j - 1][k - weight];
			}
		}
	}

	int minValue = INF;
	int res = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += w[i];
	}

	for (int i = sum % 2 == 0 ? 0 : 1; i <= sum; i += 2) {
		int a = sum / 2 - i / 2;
		int b = (sum - sum / 2) + i / 2;
		if (dp[N / 2][a] || dp[N / 2][b]) {
			cout << a << ' ' << b << '\n';
			break;
		}
	}

	//for (int i = 0; i < dp[0].size(); i++) {
	//	if (dp[N / 2][i] && sum - i < minValue) {
	//		minValue = sum - i;
	//		res = i;
	//	}
	//}

	//cout << min(sum - res, res) << ' ' << max(sum - res, res) << '\n';

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