
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

void Init(vector<int>& segtree, const vector<int>& nums, int node, int start, int end) {
	if (start == end) {
		segtree[node] = nums[start];
		return;
	}

	int mid = (start + end) / 2;
	Init(segtree, nums, node * 2, start, mid);
	Init(segtree, nums, node * 2 + 1, mid + 1, end);
	segtree[node] = min(segtree[node * 2], segtree[node * 2 + 1]);
}

int Find(vector<int>& segtree, int node, int start, int end, int left, int right) {
	//cout << node << " " << segtree[node] << " " << start << " " << end << endl;
	if (end < left || right < start) {
		return INF;
	}

	if (left <= start && end <= right) {
		return segtree[node];
	}

	int mid = (start + end) / 2;
	int l = Find(segtree, node * 2, start, mid, left, right);
	int r = Find(segtree, node * 2 + 1, mid + 1, end, left, right);


	return min(l, r);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> nums(N);
	vector<int> segtree(N * 4);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	Init(segtree, nums, 1, 0, N - 1);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << Find(segtree, 1, 0, N - 1, a - 1, b - 1) << '\n';
	}
	//a = 6, b = 9;
	//cout << Find(segtree, 1, 0, N - 1, a - 1, b - 1) << endl;

	//PrintVec(segtree);


	return 0;
}