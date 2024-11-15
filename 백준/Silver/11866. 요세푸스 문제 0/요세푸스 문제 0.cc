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

	int N, K;
	cin >> N >> K;

	queue<int> q;
	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}

	vector<int> nums;

	while (!q.empty()) {

		int cnt = 0;
		for (int i = 0; i < K - 1; i++) {
			int num = q.front();
			q.pop();
			q.push(num);
		}

		nums.push_back(q.front());
		q.pop();
	}

	//PrintVec(nums);

	cout << "<" << nums[0];
	for (int i = 1; i < N; i++) {
		cout << ", " << nums[i];
	}
	cout << ">";


	return 0;
}