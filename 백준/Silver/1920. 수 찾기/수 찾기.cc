#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

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

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

int Find(vector<int>& nums, int input) {

	if (nums[0] > input || nums.back() < input) {
		return 0;
	}

	int left = 0;
	int right = nums.size() - 1;

	while (left <= right) {
		int mid = (right + left) / 2;

		if (nums[mid] == input) {
			return 1;
		}
		else if (nums[mid] > input) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return 0;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int>nums(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	int M;
	cin >> M;
	vector<int> inputs(M);
	for (int i = 0; i < M; i++) {
		cin >> inputs[i];
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < M; i++) {
		int input = inputs[i];

		cout << Find(nums, input) << " ";
	}


	return 0;
}