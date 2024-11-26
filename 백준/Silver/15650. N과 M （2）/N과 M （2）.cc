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

void PrintComb(vector<int>& nums, int M) {
	vector<bool> check(nums.size());
	for (int i = 0; i < M; i++) {
		check[i] = true;
	}

	do {

		for (int i = 0; i < nums.size(); i++) {
			if (check[i]) {
				cout << nums[i] << ' ';
			}
		}
		cout << '\n';

	} while (prev_permutation(check.begin(), check.end()));

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> nums(N);
	for (int i = 0; i < N; i++) {
		nums[i] = i + 1;
	}

	PrintComb(nums, M);


	return 0;
}