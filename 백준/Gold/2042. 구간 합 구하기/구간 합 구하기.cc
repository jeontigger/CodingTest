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

void Init(vector<long long>& segtree, const vector<long long>& arr, long long node, long long start, long long end) {
	if (start == end) {
		segtree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	Init(segtree, arr, node * 2, start, mid);
	Init(segtree, arr, node * 2 + 1, mid + 1, end);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

long long Sum(const vector<long long>& segtree, long long node, long long start, long long end, long long left, long long right) {
	if (start > right || end < left) {
		return 0;
	}
	if (left <= start && end <= right) {
		return segtree[node];
	}

	long long mid = (start + end) / 2;
	long long lsum = Sum(segtree, node * 2, start, mid, left, right);
	long long rsum = Sum(segtree, node * 2 + 1, mid + 1, end, left, right);
	return lsum + rsum;
}

void Change(vector<long long>& segtree, long long node, long long start, long long end, long long idx, long long val) {
	if (start > idx || end < idx) {
		return;
	}

	if (start == end) {
		segtree[node] = val;
		return;
	}

	int mid = (start + end) / 2;
	Change(segtree, node * 2, start, mid, idx, val);
	Change(segtree, node * 2 + 1, mid + 1, end, idx, val);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	vector<long long> nums(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}


	long long a, b, c;
	vector<long long> segtree(4 * N);

	Init(segtree, nums, 1, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			// b번째를 c로 수 바꾸기
			Change(segtree, 1, 0, N - 1, b - 1, c);
		}
		else {
			// b번째부터 c번째까지 수의 합 구하기 - 이거만 출력
			cout << Sum(segtree, 1, 0, N - 1, b - 1, c - 1) << " ";
		}
	}


	return 0;
}