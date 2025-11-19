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

int N, K;
string Names[300000];

void Inputs() {
	cin >> N >> K;
	FOR(i, N)
		cin >> Names[i];
}

void Solution() {
	long long left = 0, ret = 0;
	int cnts[21];
	memset(cnts, 0, sizeof(cnts));

	for (int right = 0; right < N; right++) {
		cnts[Names[right].size()]++;

		while (right - left > K) {
			cnts[Names[left++].size()]--;
		}

		if (cnts[Names[right].size()] > 1)
			ret += cnts[Names[right].size()] - 1;
	}

	cout << ret << '\n';
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