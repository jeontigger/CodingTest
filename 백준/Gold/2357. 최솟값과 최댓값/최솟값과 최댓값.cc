#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

using namespace std;

#define INF (int)1e9

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

struct Data {
	int min = INF;
	int max;
};

void Init(vector<Data>& tree, const vector<int>& nums, int node, int start, int end) {
	if (start == end) {
		tree[node].min = nums[start];
		tree[node].max = nums[start];
		return;
	}

	int mid = (start + end) / 2;
	Init(tree, nums, node * 2, start, mid);
	Init(tree, nums, node * 2 + 1, mid + 1, end);
	tree[node].max = max(tree[node * 2].max, tree[node * 2 + 1].max);
	tree[node].min = min(tree[node * 2].min, tree[node * 2 + 1].min);

}

Data Query(const vector<Data>& tree, int node, int start, int end, int left, int right) {
	if (right < start || end < left) {
		return {};
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	Data d1 = Query(tree, node * 2, start, mid, left, right);
	Data d2 = Query(tree, node * 2 + 1, mid + 1, end, left, right);
	return { min(d1.min, d2.min), max(d1.max, d2.max) };
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> nums(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	vector<Data> tree(4 * N);
	Init(tree, nums, 1, 0, N - 1);

	int left, right;
	for (int i = 0; i < M; i++) {
		cin >> left >> right;
		left--;
		right--;

		Data d = Query(tree, 1, 0, N - 1, left, right);
		cout << d.min << " " << d.max << '\n';
	}

	return 0;
}