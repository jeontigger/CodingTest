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
	vector<int> fruits(N);
	for (int i = 0; i < N; i++) {
		cin >> fruits[i];
	}

	int cnt = 0, left = 0;
	vector<int> cnts(11);
	int maxLen = 0;
	for (int right = 0; right < N; right++) {
		int curFruit = fruits[right];
		if (cnts[curFruit]++ == 0) {
			cnt++;
		}

		while (cnt > 2) {
			if (--cnts[fruits[left++]] == 0) {
				cnt--;
			}
		}

		maxLen = max(maxLen, right - left + 1);
	}

	cout << maxLen;
	return 0;
}