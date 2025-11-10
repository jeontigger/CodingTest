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

int N, M, H;
vector<vector<int>> blocks;
void Inputs() {
	cin >> N >> M >> H;
	blocks.resize(N);

	string s;
	getline(cin, s);
	FOR(i, N) {
		string str, token;
		getline(cin, str);
		stringstream ss(str);
		while (ss >> token) {
			blocks[i].push_back(stoi(token));
		}
	}
}

void Solution() {
	// [높이] = 경우의 수
	vector<int> dp(2001, 0);
	dp[0] = 1;

	// 사람, 블럭 순
	for (int i = 0; i < N; i++) {
		auto before = dp;
		for (int j = 0; j < blocks[i].size(); j++) {
			for (int k = blocks[i][j]; k < dp.size(); k++) {
				dp[k] += before[k - blocks[i][j]];
				dp[k] = dp[k] % 10007;
			}
		}
	}

	cout << dp[H] % 10007;
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