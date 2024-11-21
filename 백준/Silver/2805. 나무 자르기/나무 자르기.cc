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

bool IsPossible(vector<int>& trees, int curHeight, int target) {

	long long sum = 0;
	for (int i = 0; i < trees.size(); i++) {
		if (trees[i] > curHeight) {
			sum += trees[i] - curHeight;
		}

		if (sum >= target) {
			return true;
		}
	}

	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> trees(N);
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}

	long long left = 1;
	long long right = 2e9;
	while (left <= right) {
		long long mid = (left + right) / 2;

		if (IsPossible(trees, mid, M)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << right;

	return 0;
}