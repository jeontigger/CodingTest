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

	vector<int> nums(4000001);
	vector<int> primes;
	primes.push_back(2);
	// 짝수 판정
	for (int i = 2; i < 4000001; i += 2) {
		nums[i] = 2;
	}
	for (int i = 3; i < 4000001; i += 2) {
		if (nums[i] == 0) {
			nums[i] = i;
			primes.push_back(i);
			for (int j = i * 2; j < 4000001; j += i) {
				nums[j] = i;
			}
		}
	}

	int left = 0;
	int sum = 0;
	int cnt = 0;
	for (int right = 0; right < primes.size(); right++) {
		sum += primes[right];

		while (sum > N) {
			sum -= primes[left];
			left++;
		}

		if (sum == N) {
			cnt++;
		}
	}

	cout << cnt;


	return 0;
}