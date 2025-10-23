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

int L, R;
void Inputs() {
	cin >> L >> R;
}

long long combination(int n, int r) {
	if (r > n) swap(n, r);
	if (r > n / 2) r = n - r; // C(n, r) == C(n, n-r)
	long long numerator = 1;
	long long denominator = 1;
	for (int i = 0; i < r; i++) {
		numerator *= (n - i);
		denominator *= (i + 1);
	}
	return numerator / denominator;
}

void Solution() {
	cout << combination(L, R) << '\n';
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