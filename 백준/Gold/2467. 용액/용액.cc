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

	int left = 0, right = N - 1;
	int sum = INF * 2;

	int minLeft, minRight;
	while (left < right) {
		int val = nums[left] + nums[right];
		if (abs(val) < sum) {
			minLeft = nums[left];
			minRight = nums[right];
			sum = abs(val);
		}

		if (val > 0) {
			right--;
		}
		else {
			left++;
		}
	}

	cout << minLeft << " " << minRight;

	return 0;
}