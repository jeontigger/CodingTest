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
	vector<int> ranks(N);
	for (int i = 0; i < N; i++) {
		cin >> ranks[i];
	}

	int except = round(N * 0.15);
	sort(ranks.begin(), ranks.end());

	int sum = 0;
	for (int i = except; i < N - except; i++) {
		sum += ranks[i];
	}

	//cout << sum << endl;
	if (N == 0) {
		cout << 0;
	}
	else {
		cout << round((double)sum / (N - 2 * except));
	}


	return 0;
}