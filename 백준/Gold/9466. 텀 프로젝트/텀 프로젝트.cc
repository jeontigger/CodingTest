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
#include <iomanip>
#include <cassert>
#include <cstring>
#include <list>

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
#define FOR(idx, limit) for(int idx = 0; idx < limit; idx++)

int N;
vector<int> nums, visited, finished;

bool Inputs() {
	cin >> N;
	nums.resize(N + 1);
	visited.assign(N + 1, 0);
	finished.assign(N + 1, 0);
	FOR(i, N)
		cin >> nums[i + 1];
	return true;
}

int DFS(int idx) {
	int ret = 0;

	int next = nums[idx];
	if (!visited[next]) {
		visited[next] = true;
		ret += DFS(next);
	}
	else if (!finished[next]) {
		int cur = nums[idx];
		while (true) {
			ret++;
			if (cur == idx) break;
			cur = nums[cur];
		}
	}

	finished[idx] = true;

	return ret;
}

void Solution() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ret += DFS(i);
		}
	}

	cout << N - ret << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	cin >> T;
	while (T--) {
		if (!Inputs()) break;
		Solution();
	}


	return 0;
}