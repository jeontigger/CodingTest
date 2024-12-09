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

vector<int> LIS(const vector<int>& arrs) {
	vector<int> res(arrs.size());
	res[0] = 1;

	vector<int> lis;
	lis.push_back(arrs[0]);

	for (int i = 1; i < arrs.size(); i++) {
		if (arrs[i] > lis.back()) {
			lis.push_back(arrs[i]);
		}
		else {
			*lower_bound(lis.begin(), lis.end(), arrs[i]) = arrs[i];
		}

		res[i] = lis.size();
	}

	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	nums.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	auto r1 = LIS(nums);
	reverse(nums.begin(), nums.end());
	auto r2 = LIS(nums);

	int maxValue = 0;
	for (int i = 0; i < N; i++) {
		maxValue = max(maxValue, r1[i] + r2[N - 1 - i]);
	}

	cout << maxValue - 1;


	//PrintVec(r1);
	//reverse(r2.begin(), r2.end());
	//PrintVec(r2);

	return 0;
}
