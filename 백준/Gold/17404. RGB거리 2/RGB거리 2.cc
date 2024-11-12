#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <set>

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

struct Color {
	int r;
	int g;
	int b;
};

enum color {
	R,
	G,
	B
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<Color> colors(N);
	for (int i = 0; i < N; i++) {
		cin >> colors[i].r >> colors[i].g >> colors[i].b;
	}

	// R을 선택했을 때, G를 선택했을 때, B를 선택했을 때

	int minValue = INF;
	for (int i = 0; i < 3; i++) {
		vector<vector<int>> dp(N, vector<int>(3, INF));
		switch (i) {
		case R:
			dp[0][R] = colors[0].r;
			break;
		case G:
			dp[0][G] = colors[0].g;
			break;
		case B:
			dp[0][B] = colors[0].b;
			break;
		}

		for (int i = 1; i < N; i++) {
			dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + colors[i].r;
			dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + colors[i].g;
			dp[i][B] = min(dp[i - 1][G], dp[i - 1][R]) + colors[i].b;
		}

		//PrintVec(dp);

		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			minValue = min(minValue, dp.back()[j]);
		}
	}

	cout << minValue;

	return 0;
}