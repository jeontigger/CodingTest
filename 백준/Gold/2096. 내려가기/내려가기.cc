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

	vector<int> dp(3);
	vector<int> mindp(3);
	cin >> dp[0] >> dp[1] >> dp[2];
	mindp = dp;

	for (int i = 1; i < N; i++) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		auto pdp = dp;
		dp[0] = max(pdp[0], pdp[1]) + n1;
		dp[1] = max(max(pdp[0], pdp[1]), pdp[2]) + n2;
		dp[2] = max(pdp[1], pdp[2]) + n3;

		pdp = mindp;
		mindp[0] = min(pdp[0], pdp[1]) + n1;
		mindp[1] = min(min(pdp[0], pdp[1]), pdp[2]) + n2;
		mindp[2] = min(pdp[1], pdp[2]) + n3;
	}

	cout << *max_element(dp.begin(), dp.end()) << ' ' << *min_element(mindp.begin(), mindp.end());

	return 0;
}