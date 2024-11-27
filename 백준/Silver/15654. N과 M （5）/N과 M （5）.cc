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

vector<int> nums;
vector<bool> visited;

void PrintCombination(int M, vector<int>& path) {

	if (M == 0) {
		PrintVec(path);
		return;
	}

	for (int i = 0; i < nums.size(); i++) {
		if (visited[i]) continue;
		path.push_back(nums[i]);
		visited[i] = true;
		PrintCombination(M - 1, path);
		visited[i] = false;
		path.pop_back();
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	nums.resize(N);
	visited.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());

	vector<int> path;
	PrintCombination(M, path);

	return 0;
}