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
#include <iomanip>
#include <cassert>
#include <cstring>
#include <list>

using namespace std;

#define INF 1e9

template<typename T>
void PrintVec(const vector<T>& v) {
	for (T i : v) {
		cout << i << " ";
	}
	cout << '\n';
}

template<typename T>
void PrintVec(const vector<vector<T>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}
#define FOR(idx, limit) for(int idx = 0; idx < limit; idx++)

int N;
vector<int> nums;

void Inputs() {
	cin >> N;
	nums.resize(N);
	FOR(i, N) {
		cin >> nums[i];
	}
}

constexpr int MAX_SIZE = 1000001;
bool isPrime[MAX_SIZE];
vector<int> primes;

void Init() {
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 4; i < MAX_SIZE; i += 2) {
		isPrime[i] = false;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	isPrime[2] = true;
	primes.push_back(2);
	for (int i = 3; i < MAX_SIZE; i += 2) {
		if (isPrime[i] == true) {
			primes.push_back(i);
			for (int j = i + i; j < MAX_SIZE; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int CountingSum(int num) {
	int l = 0;
	int r = primes.size() - 1;

	int ret = 0;

	while (l <= r) {
		int sum = primes[l] + primes[r];
		if (sum == num) {
			ret++;
			l++;
			r--;
		}
		else if (sum < num) {
			l++;
		}
		else if (sum > num) {
			r--;
		}
	}

	return ret;
}

void Solution() {
	Init();

	for (int i = 0; i < N; i++) {
		cout << CountingSum(nums[i]) << '\n';
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	//cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}