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
	cout << '\n';
}

template<typename T>
void PrintVec(const vector<vector<T>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

vector<int> visited;
vector<int> nums;
set<vector<int>> s;
int N, M;

void PrintCombination(int k, vector<int>& path, int startIdx) {

	if (k == 0) {
		PrintVec(path);

		return;
	}

	int prev = -1;
	for (int i = startIdx; i < N; i++) {
		if (nums[i] == prev) continue;

		prev = nums[i];
		path.push_back(nums[i]);
		PrintCombination(k - 1, path, i);
		path.pop_back();
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	nums.resize(N);
	visited.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	vector<int> path;
	PrintCombination(M, path, 0);

	return 0;
}