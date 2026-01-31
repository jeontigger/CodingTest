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

int N, K;
int nums[200001];

bool Inputs() {
	cin >> N >> K;

	FOR(i, N)
		cin >> nums[i];

	return true;
}

void Solution() {
	// [i][j] => i~j-1부터 j까지의 합
	unordered_map<long long, long long> cnts(N);

	long long cnt = 0;
	long long sum = 0;
	cnts[0] = 1;
	// k일 때, i~k-1부터 k-1까지
	for (int i = 0; i < N; i++) {
		sum += nums[i];
		cnt += cnts[sum - K];
		cnts[sum]++;
	}

	cout << cnt << '\n';
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