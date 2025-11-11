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

int N, X, Y, x[50], y[50];
int XMax, YMax;
void Inputs() {
	cin >> N >> X >> Y;
	XMax = YMax = 0;
	FOR(i, N) {
		cin >> x[i] >> y[i];
		XMax += x[i];
		YMax += y[i];
	}
}

void Solution() {
	vector<vector<pair<int, int>>> dp(201, vector<pair<int, int>>(201, { INF, -1 }));
	XMax = YMax = 201;
	dp[0][0] = { 0, -1 };
	for (int i = 0; i < N; i++) {
		int curx = x[i], cury = y[i];
		auto before = dp;
		for (int j = curx; j < XMax; j++) {
			for (int k = cury; k < YMax; k++) {
				if (dp[j][k].first > before[j - curx][k - cury].first + 1) {
					dp[j][k] = { before[j - curx][k - cury].first + 1, i };
				}
			}
		}
	}

	int cnt = INF, idx = -1;
	for (int i = X; i < XMax; i++) {
		for (int j = Y; j < YMax; j++) {
			if (dp[i][j].first < cnt) {
				cnt = dp[i][j].first;
				idx = dp[i][j].second;
			}
			else if (dp[i][j].first == cnt && idx > dp[i][j].second) {
				cnt = dp[i][j].first;
				idx = dp[i][j].second;
			}
		}
	}

	if (cnt == INF)
		cout << -1 << '\n';
	else {
		cout << cnt << '\n';
		cout << idx + 1 << '\n';
	}
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