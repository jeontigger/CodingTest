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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> nums(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += nums[i];
	}

	int maxValue = sum;

	for (int i = K; i < N; i++) {
		sum += nums[i];
		sum -= nums[i - K];

		maxValue = max(sum, maxValue);
	}

	cout << maxValue;

	return 0;
}