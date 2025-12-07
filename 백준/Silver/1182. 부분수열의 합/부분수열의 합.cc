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

int N, S;
vector<int> nums;

bool Inputs() {
	cin >> N >> S;
	nums.resize(N);
	FOR(i, N)
		cin >> nums[i];

	return true;
}

int DFS(int idx, int cur) {
	if (idx == N) {
		return cur == S;
	}

	//if (nums[idx] + cur > S) return cur == S;

	int ret = 0;
	ret += DFS(idx + 1, cur);
	ret += DFS(idx + 1, cur + nums[idx]);

	return ret;
}

void Solution() {
	sort(nums.begin(), nums.end());
	int ret = DFS(0, 0);
	if (S == 0) ret--;
	cout << ret << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	//cin >> T;
	while (T--) {
		if (!Inputs()) break;
		Solution();
	}


	return 0;
}