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

long long  Fact(int n) {
	long long res = 1;

	for (int i = 1; i < n; i++) {
		cout << res << " " << i - 1 << endl;
		res *= i;
	}

	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int>nums(N);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());
	PrintVec(nums);

	return 0;
}