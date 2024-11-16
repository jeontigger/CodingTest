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
	int val;
	int cnt;
};

struct cmp {
	bool operator()(const Data& d1, const Data& d2) {
		return d1.cnt == d2.cnt ? d1.val > d2.val : d1.cnt < d2.cnt;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> cnts(80001);
	int N;
	cin >> N;
	vector<int> nums(N);

	int sum = 0;
	int maxValue = -5000;
	int minValue = 5000;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		cnts[nums[i] + 4000]++;

		sum += nums[i];
		minValue = min(minValue, nums[i]);
		maxValue = max(maxValue, nums[i]);
	}

	priority_queue<Data, vector<Data>, cmp>pq;
	for (int i = 0; i < cnts.size(); i++) {
		if (cnts[i] != 0)
			pq.push({ i - 4000, cnts[i] });
	}

	Data d1 = pq.top();
	pq.pop();
	Data d2;
	d2.cnt = 0;
	if (!pq.empty()) {
		d2 = pq.top();
	}

	if (d1.cnt == d2.cnt)
		d1.val = d2.val;

	sort(nums.begin(), nums.end());

	int res = round((double)sum / N);
	if (res == 0) {
		res = 0;
	}
	cout << res << '\n';
	cout << nums[N / 2] << '\n';
	cout << d1.val << '\n';
	cout << maxValue - minValue << '\n';




	return 0;
}