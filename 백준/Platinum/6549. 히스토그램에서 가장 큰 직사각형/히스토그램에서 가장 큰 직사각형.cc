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

int N;
long long graph[100001];

void Inputs() {
	FOR(i, N) {
		cin >> graph[i];
	}
}


long long DC(int left, int right) {
	int size = right - left + 1;
	if (size == 1) return graph[left];

	long long ret = 0;
	int half = (left + right) / 2;
	ret = max(DC(left, half), DC(half + 1, right));

	long long l = half, r = half + 1;
	long long h = min(graph[l], graph[r]);
	ret = max(ret, h * 2);

	while (left < l || r < right) {
		if (r < right && (left == l || graph[r + 1] > graph[l - 1])) {
			r++;
			h = min(h, graph[r]);
		}
		else {
			l--;
			h = min(h, graph[l]);
		}
		ret = max(ret, (r - l + 1) * h);
	}

	return ret;
}

void Solution() {
	cout << DC(0, N - 1) << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	//cin >> T;
	while (true) {
		cin >> N;
		if (N == 0) break;
		Inputs();
		Solution();
	}


	return 0;
}