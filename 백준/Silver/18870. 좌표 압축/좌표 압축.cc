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

struct Data {
	int idx;
	int value;
};

struct cmp {
	bool operator()(const Data& d1, const Data& d2) {
		return d1.value > d2.value;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> nums(N);
	priority_queue<Data, vector<Data>, cmp> pq;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		pq.push({ i, nums[i] });
	}

	vector<int> relative(N);

	int prev = pq.top().value;
	int cnt = 0;
	relative[pq.top().idx] = cnt;
	pq.pop();

	while (!pq.empty()) {
		if (prev != pq.top().value) {
			cnt++;
		}
		relative[pq.top().idx] = cnt;
		prev = pq.top().value;
		pq.pop();
	}

	PrintVec(relative);



	return 0;
}