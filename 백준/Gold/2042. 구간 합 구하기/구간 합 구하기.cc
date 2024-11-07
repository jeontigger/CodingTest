
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

using namespace std;

#define INF 1e9

template<typename T>
void PrintVec(const vector<T>& v) {
	for (T i : v) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T>
void PrintVec(const vector<vector<T>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

vector<long long> fenwick;

void Update(int idx, long long value) {
	while (idx < fenwick.size()) {
		fenwick[idx] += value;
		idx = idx + (idx & -idx);
	}
}

long long Sum(int idx) {
	long long sum = 0;
	while (idx > 0) {
		sum += fenwick[idx];
		idx = idx - (idx & -idx);
	}
	return sum;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	vector<long long> nums(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
	}

	fenwick.resize(N + 1);

	// init
	for (int i = 1; i <= N; i++) {
		Update(i, nums[i]);
	}

	long long a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			// update
			Update(b, c - nums[b]);
			nums[b] = c;
		}
		else {
			// sum
			cout << Sum(c) - Sum(b - 1) << '\n';
		}
	}


	return 0;
}