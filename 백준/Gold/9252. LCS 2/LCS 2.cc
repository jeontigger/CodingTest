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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;

	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	int row = s1.size(), col = s2.size();

	string res = "";
	while (dp[row][col]) {

		if (dp[row][col] == dp[row - 1][col]) {
			row--;
		}

		if (dp[row][col] == dp[row][col - 1]) {
			col--;
		}

		if (dp[row][col] != dp[row - 1][col] && dp[row][col] != dp[row][col - 1]) {
			res = s1[row - 1] + res;
			row--;
			col--;
		}
	}

	//PrintVec(dp);
	cout << res.size() << " " << res << endl;

	return 0;
}