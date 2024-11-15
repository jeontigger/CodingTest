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

int Fact(int r) {
	int res = 1;
	for (int i = 2; i <= r; i++) {
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
	vector<double>nums(N);

	double maxValue = 0;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];

		maxValue = max(maxValue, nums[i]);
	}

	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += ((double)nums[i] / maxValue * 100);
	}
	cout << (double)sum / N;

	return 0;
}