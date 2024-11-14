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

	vector<int> primes(N);

	for (int i = 0; i < N; i++) {
		cin >> primes[i];
	}

	int nums[1001] = { 0, };

	nums[2] = 1;
	for (int i = 4; i < 1001; i += 2) {
		nums[i] = 2;
	}

	for (int i = 3; i < 1001; i += 2) {
		if (nums[i] == 0) {
			nums[i] = 1;
		}
		for (int j = i + i; j < 1001; j += i) {
			nums[j] = 2;
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (nums[primes[i]] == 1) {
			cnt++;
		}
	}

	cout << cnt;



	return 0;
}

