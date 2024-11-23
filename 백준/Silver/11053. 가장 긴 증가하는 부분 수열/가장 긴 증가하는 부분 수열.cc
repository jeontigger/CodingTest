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

void LIS(vector<int>& nums) {
	vector<int> lis;
	lis.push_back(nums[0]);

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] > lis.back()) {
			lis.push_back(nums[i]);
		}
		else {
			auto iter = lower_bound(lis.begin(), lis.end(), nums[i]);
			*iter = nums[i];
		}
	}

	cout << lis.size();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	LIS(nums);

	return 0;
}