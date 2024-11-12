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
	vector<bool> exist(1000001);

	int maxValue = 0;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		maxValue = max(nums[i], maxValue);
		exist[nums[i]] = true;
	}

	vector<int> score(1000001);

	for (int i = 0; i < N; i++) {
		int curNum = nums[i];

		for (int j = curNum * 2; j < maxValue + 1; j += curNum) {
			if (exist[j]) {
				score[curNum]++;
				score[j]--;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << score[nums[i]] << " ";
	}

	return 0;
}