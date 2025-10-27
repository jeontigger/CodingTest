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
long long num[100001];

void Inputs() {
	cin >> N;
	FOR(i, N)
		cin >> num[i];
}

long long DC(int left, int right) {
	if (left == right) return num[left] * num[left];

	long long ret = 0;

	int half = (left + right) / 2;
	ret = max(DC(left, half), DC(half + 1, right));

	int lo = half, hi = half + 1;
	long long sum = num[lo] + num[hi];
	long long minValue = min(num[lo], num[hi]);
	ret = max(ret, minValue * sum);

	while (left < lo || hi < right) {
		if (hi < right && (lo < left || num[lo - 1] < num[hi + 1])) {
			hi++;
			sum += num[hi];
			minValue = min(minValue, num[hi]);
		}
		else {
			lo--;
			sum += num[lo];
			minValue = min(minValue, num[lo]);
		}

		ret = max(ret, minValue * sum);

	}


	return ret;
}

void Solution() {
	cout << DC(0, N - 1);
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