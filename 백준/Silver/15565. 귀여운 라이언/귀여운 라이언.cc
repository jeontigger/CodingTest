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

int N, K, nums[1000000];

void Inputs() {
	cin >> N >> K;
	FOR(i, N)
		cin >> nums[i];
}

void Solution() {
	int cnt = 0, right = 0, left = 0;
	int len = INF;
	while (left <= right) {
		while (right < N && cnt < K) {
			if (nums[right++] == 1) cnt++;
		}

		while (left <= right && nums[left++] != 1) {}

		if (cnt == K)
			len = min(len, right - left + 1);

		cnt--;
	}
	if (len == INF)
		cout << -1 << '\n';
	else
		cout << len << '\n';
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