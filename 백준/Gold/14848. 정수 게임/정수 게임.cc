
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

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

long long gcd(long long a, long long b) {

	long long c = b;
	while (c) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

long long lcm(long long a, long long b) {
	long long g = gcd(a, b);
	return a * b / g;
}

long long lcms(const vector<long long>& nums) {
	long long res = 1;
	for (int i = 0; i < nums.size(); i++) {
		res = lcm(nums[i], res);
	}

	return res;
}

vector<long long> lcmss(const vector<vector<long long>>& nums) {
	vector<long long> res;
	for (int i = 0; i < nums.size(); i++) {
		res.push_back(lcms(nums[i]));
	}

	return res;
}

vector<vector<long long>> GetCombVec(const vector<long long>& nums, int k) {
	vector<vector<long long>> res;

	vector<bool> check(nums.size());
	for (int i = 0; i < k; i++) {
		check[i] = true;
	}

	reverse(check.begin(), check.end());

	do {
		vector<long long>v;
		for (int i = 0; i < check.size(); i++) {
			if (check[i]) {
				v.push_back(nums[i]);
			}
		}
		res.push_back(v);

	} while (next_permutation(check.begin(), check.end()));

	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long  N, K;
	cin >> N >> K;

	long long res = N;
	vector<long long> nums(K);
	for (int i = 0; i < K; i++) {
		cin >> nums[i];
	}

	for (int i = 1; i <= K; i++) {
		vector<long long> vecLcms = lcmss(GetCombVec(nums, i));

		for (int j = 0; j < vecLcms.size(); j++) {

			if (i % 2 == 1) {
				res -= N / vecLcms[j];
			}
			else {
				res += N / vecLcms[j];
			}

		}
	}

	cout << res;


	return 0;
}