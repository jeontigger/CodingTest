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

void PrintMultipleComb(vector<int>& nums, int M, vector<int>& path) {

	if (M == 0) {
		PrintVec(path);
		return;
	}

	int start = path.size() == 0 ? 0 : path.back() - 1;

	for (int i = start; i < nums.size(); i++) {
		path.push_back(nums[i]);
		PrintMultipleComb(nums, M - 1, path);
		path.pop_back();
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
		nums[i] = i + 1;
	}

	vector<int> path;
	PrintMultipleComb(nums, M, path);

	return 0;
}