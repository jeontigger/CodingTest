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

#define INF 1e12

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

bool IsPossible(const vector<int>& lans, long long cmp, int N) {

	int cnt = 0;
	for (int i = 0; i < lans.size(); i++) {
		cnt += lans[i] / cmp;
	}

	return cnt >= N;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K, N;
	cin >> K >> N;
	vector<int> lans(K);
	for (int i = 0; i < K; i++) {
		cin >> lans[i];
	}

	long long left = 1;
	long long right = INF;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (IsPossible(lans, mid, N)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}

	cout << right;


	return 0;
}