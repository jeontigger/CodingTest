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

	int N, M;
	cin >> N >> M;

	vector<int> nums(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	long long sum = 0;
	int left = 0;
	int cnt = 0;
	int shortestLen = INF;
	for (int right = 0; right < N; right++) {
		sum += nums[right];
		//cout << "right " << sum << " " << left << " " << right << endl;

		while (sum >= M && left <= right) {
			shortestLen = min(shortestLen, right - left + 1);
			sum -= nums[left];
			//cout << "left " << sum << " " << left << " " << right << endl;
			left++;
		}

	}

	shortestLen == INF ? cout << 0 : cout << shortestLen;

	return 0;
}