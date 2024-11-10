#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <set>

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

vector<vector<int>> dp;
bool IsPalindrome(int left, int right) {
	return dp[left][right];
}
void MakeTable(vector<int>& nums) {
	int N = nums.size();
	dp.resize(N, vector<int>(N));
	for (int i = 1; i < N; i++) {
		dp[i][i] = 1;
	}

	for (int i = 1; i < N - 1; i++) {
		if (nums[i] == nums[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}

	for (int i = N; i >= 1; i--) {
		for (int j = i + 2; j < N; j++) {
			if (IsPalindrome(i + 1, j - 1) && nums[i] == nums[j]) {
				dp[i][j] = 1;
			}
		}
	}

	//PrintVec(dp);
}




int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> nums(N + 1);
	for (int i = 1; i < nums.size(); i++) {
		cin >> nums[i];
	}

	MakeTable(nums);

	int M;
	cin >> M;
	int l, r;
	for (int i = 0; i < M; i++) {
		cin >> l >> r;
		cout << IsPalindrome(l, r) << " ";
	}




	return 0;
}