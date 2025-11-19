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

int N, M, K, Money[100000];

void Inputs() {
	cin >> N >> M >> K;
	FOR(i, N)
		cin >> Money[i];
}

void Solution() {
	if (N == M) {
		int sum = 0;
		for (int i = 0; i < N; i++)
			sum += Money[i];
		if (sum < K)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
		return;
	}

	int ret = 0, left = 0, sum = 0;
	for (int right = 0; right < N + M - 1; right++) {
		sum += Money[right % N];

		while (right - left + 1 >= M) {
			if (sum < K)
				ret++;
			sum -= Money[left % N];
			left++;
		}
	}

	cout << ret << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}