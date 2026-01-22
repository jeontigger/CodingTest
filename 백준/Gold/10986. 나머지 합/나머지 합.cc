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
int nums[1000001], cnts[1001];
bool Inputs() {
	cin >> N >> M;
	FOR(i, N)
		cin >> nums[i];
	return true;
}

void Solution() {
	cnts[0] = 1;

	int prefix = 0;
	long long answer = 0;
	for (int i = 0; i < N; i++) {
		prefix = (prefix + nums[i]) % M;
		answer += cnts[prefix];
		cnts[prefix]++;
	}

	cout << answer;
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