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

long long N;
string cache[61][2];

void Inputs() {
	cin >> N;
}

long long GetN(long long len) {
	long long l = 1;
	long long cnt = 0;
	while (l < len) {
		l <<= 1;
		cnt++;
	}

	return cnt;
}

int DC(long long left, long long right, bool origin) {
	if (left == right) {
		if (origin)
			return 0;
		else
			return 1;
	}

	long long mid = (left + right) / 2;
	if (N - 1 <= mid) {
		return DC(left, mid, origin);
	}
	else {
		return DC(mid + 1, right, !origin);
	}
}

void Solution() {
	// 1이면 0, 2면 1, 3이면 2, 4면 2, 5면 3
	long long l = GetN(N);

	cout << DC(0, (long long)pow((long long)2, l) - 1, true);

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