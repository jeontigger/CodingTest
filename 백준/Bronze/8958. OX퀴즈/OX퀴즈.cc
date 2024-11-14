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

	int T;
	cin >> T;

	string str;
	while (T--) {
		cin >> str;

		int score = 1;
		int sum = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'X') {
				score = 1;
			}
			else {
				sum += score++;
			}
		}
		cout << sum << " ";
	}

	return 0;
}

