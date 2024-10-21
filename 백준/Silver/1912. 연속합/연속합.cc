#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1e9

void PrintVec(const vector<int>& v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {

	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	vector<int> dp(n);
	dp[0] = nums[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(nums[i], dp[i - 1] + nums[i]);
	}

	//PrintVec(dp);
	cout << *max_element(dp.begin(), dp.end());


	return 0;
}