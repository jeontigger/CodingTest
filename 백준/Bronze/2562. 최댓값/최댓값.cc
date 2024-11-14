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

	int idx = 0;
	int num;

	int maxValue = 0;
	for (int i = 0; i < 9; i++) {
		cin >> num;

		if (maxValue < num) {
			idx = i + 1;
			maxValue = num;
		}
	}

	cout << maxValue << " " << idx << endl;
	return 0;
}

