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

int N, M;
vector<int> nums;
vector<int> visited;
vector<int> last;
set<vector<int>> s;
void NM(vector<int>& res) {
	// 기저사례
	if (res.size() == M) {
		s.insert(res);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			res.push_back(nums[i]);
			NM(res);
			res.pop_back();
			visited[i] = false;
		}
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
	//PrintVec(nums);

	vector<int> res;
	NM(res);

	for (const vector<int>& v : s) {
		PrintVec(v);
	}

	return 0;
}
