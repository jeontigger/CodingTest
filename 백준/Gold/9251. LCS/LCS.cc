#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1e9

void PrintVec(const vector<int>& v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {

	string s1, s2;

	cin >> s1;
	cin >> s2;

	vector<vector<int>> dp(s2.length() + 1, vector<int>(s1.length() + 1));

	for (int i = 1; i <= s2.length(); i++) {
		for (int j = 1; j <= s1.length(); j++) {
			if (s1[j - 1] == s2[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	//for (auto& v : dp) {
	//	PrintVec(v);
	//}

	cout << *max_element(dp.back().begin(), dp.back().end());



	return 0;
}