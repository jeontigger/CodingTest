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
	while (true) {
		int num;
		cin >> num;
		if (num == 0) break;

		nums.push_back(num);
	}

	N = nums.size();
}

constexpr int MAX_SIZE = 300000;
bool isPrime[MAX_SIZE];

void Init() {
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 4; i < MAX_SIZE; i += 2) {
		isPrime[i] = false;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	isPrime[2] = true;
	for (int i = 3; i < MAX_SIZE; i += 2) {
		if (isPrime[i] == true) {
			for (int j = i + i; j < MAX_SIZE; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int CountingPrime(int num) {
	int ret = 0;

	for (int i = num + 1; i <= num * 2; i++) {
		if (isPrime[i]) ret++;
	}

	return ret;
}

void Solution() {
	Init();

	for (int i = 0; i < N; i++) {
		cout << CountingPrime(nums[i]) << '\n';
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