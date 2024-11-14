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

	int a, b, c;


	while (true) {
		cin >> a >> b >> c;

		if (a == b && b == c && a == 0) break;

		vector<int>nums(3);
		nums[0] = a;
		nums[1] = b;
		nums[2] = c;

		sort(nums.begin(), nums.end());

		if (nums[2] * nums[2] == nums[1] * nums[1] + nums[0] * nums[0]) {
			cout << "right" << '\n';
		}
		else {
			cout << "wrong" << '\n';
		}

	}

	return 0;
}

