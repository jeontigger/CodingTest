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

	vector<int> table(N + 1);
	table[0] = 0;
	for (int i = 1; i < table.size(); i++) {
		table[i] = table[i - 1] + nums[i - 1];
	}

	for (int i = 0; i < M; i++) {
		int l, r;
		cin >> l >> r;
		cout << table[r] - table[l - 1] << ' ';

	}

	return 0;
}