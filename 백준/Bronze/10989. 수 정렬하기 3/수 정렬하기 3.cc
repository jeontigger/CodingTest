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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int n;
	vector<int> nums(10001);
	for (int i = 0; i < N; i++) {
		cin >> n;
		nums[n]++;
	}

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 0) continue;
		for (int j = 0; j < nums[i]; j++) {
			cout << i << " ";
		}
	}


	return 0;
}