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

	int N, K;
	cin >> N >> K;

	vector<int> coins(N);
	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}

	int cnt = 0;
	while (K) {
		auto iter = lower_bound(coins.begin(), coins.end(), K);
		if (*iter == K) {
			cnt++;
			K -= *iter;
		}
		else {
			iter--;
			cnt += (K / *iter);
			K -= (K / *iter) * *iter;
			//K -= *iter;
		}

		//cout << K << " ";
	}

	cout << cnt;


	return 0;
}