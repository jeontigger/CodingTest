
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

struct Data {
	int cost;
	int cnt;
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	unordered_map<int, int> m;
	vector<Data> candies;
	int candy;
	for (int i = 0; i < N; i++) {
		cin >> candy;
		m[candy]++;
	}

	for (auto iter = m.begin(); iter != m.end(); ++iter) {
		candies.push_back({ iter->first, iter->second });
	}

	vector<long long> dp(500001);
	dp[0] = 1;

	for (int i = 0; i < candies.size(); i++) {
		vector<long long> pdp = dp;
		for (int j = 0; j < dp.size(); j++) {
			for (int k = 1; k <= candies[i].cnt; k++) {
				if (j - candies[i].cost * k < 0) break;
				dp[j] += pdp[j - candies[i].cost * k];
			}
		}
	}


	vector<int> primes(500001);

	for (int i = 2; i < primes.size(); i++) {
		if (primes[i] == 0) {
			for (int j = i; j < primes.size(); j += i) {
				primes[j] = 1;
			}
			primes[i] = -1;
		}
	}

	long long res = 0;
	for (int i = 0; i < dp.size(); i++) {
		if (primes[i] == -1) {
			res += dp[i];
			//cout << i << " " << dp[i] << endl;
		}
	}
	cout << res;

	return 0;
}