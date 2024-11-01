#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

using namespace std;

#define INF 1e12

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

void Init(vector<long long>& segtree, const vector<int>& nums, int node, int start, int end) {

	if (start == end) {
		segtree[node] = nums[start];
		return;
	}

	int mid = (start + end) / 2;
	Init(segtree, nums, node * 2, start, mid);
	Init(segtree, nums, node * 2 + 1, mid + 1, end);
	segtree[node] = (segtree[node * 2] * segtree[node * 2 + 1]) % 1000000007;
}

long long GetMul(vector<long long>& segtree, int node, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return 1;
	}

	if (left <= start && end <= right) {
		//cout << start << " " << end << " " << left << " " << right << endl;
		return segtree[node];
	}

	int mid = (start + end) / 2;
	long long lv = GetMul(segtree, node * 2, start, mid, left, right);
	long long rv = GetMul(segtree, node * 2 + 1, mid + 1, end, left, right);

	return (lv * rv) % 1000000007;
}

void Change(vector<long long>& segtree, int node, int start, int end, int idx, int value) {
	if (end < idx || idx < start) {
		return;
	}
	if (start == end) {
		segtree[node] = value;
		return;
	}

	int mid = (start + end) / 2;
	Change(segtree, node * 2, start, mid, idx, value);
	Change(segtree, node * 2 + 1, mid + 1, end, idx, value);
	segtree[node] = (segtree[node * 2] * segtree[node * 2 + 1]) % 1000000007;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	vector<int>nums(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	vector<long long> segtree(N * 4);

	Init(segtree, nums, 1, 0, N - 1);

	int c, a, b;
	for (int i = 0; i < M + K; i++) {
		cin >> c >> a >> b;
		if (c == 1) {
			// change
			Change(segtree, 1, 0, N - 1, a - 1, b);
			//PrintVec(segtree);
		}
		else {
			// mul
			cout << GetMul(segtree, 1, 0, N - 1, a - 1, b - 1) << endl;
		}
	}

	return 0;
}