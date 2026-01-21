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
#include <map>

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

int N, M;
vector<int> nums;
int sum[300002], l[300001], r[300001];

bool Inputs() {
	cin >> N >> M;
	nums.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	FOR(i, M) {
		cin >> l[i] >> r[i];
	}

	sort(nums.begin(), nums.end(), less<int>());
	return true;
}

void Init() {
	sum[0] = 0;
	for (int i = 0; i < N; i++) {
		sum[i + 1] = sum[i] + nums[i];
	}
}

void Solution() {
	Init();

	for (int i = 0; i < M; i++) {
		cout << sum[r[i]] - sum[l[i] - 1] << '\n';
	}
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