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
vector<int> nums;
void Inputs() {
	cin >> N;
	nums.resize(N);
	FOR(i, N) {
		cin >> nums[i];
	}
}

void Solution() {

	stack<int> s;
	int cur = 1;
	for (int i = 0; i < N; i++) {
		if (!s.empty() && s.top() == cur) {
			s.pop();
			cur++;
			i--;
		}
		else if (nums[i] != cur) {
			s.push(nums[i]);
		}
		else {
			cur++;
		}
	}

	while (!s.empty()) {
		if (s.top() != cur) {
			cout << "Sad\n";
			return;
		}

		s.pop();
		cur++;
	}

	cout << "Nice\n";

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	//cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}