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

	vector<int> tang(N);
	for (int i = 0; i < N; i++) {
		cin >> tang[i];
	}

	set<int> s;
	int left = 0;
	int maxValue = 0;
	for (int right = 0; right < N; right++) {
		s.insert(tang[right]);

		if (s.size() > 2) {
			left = right - 1;
			while (tang[left] == tang[left - 1]) {
				left--;
			}
			s.erase(tang[left - 1]);
		}
		//cout << left << " " << right << endl;
		maxValue = max(maxValue, right - left + 1);
	}
	cout << maxValue;

	return 0;
}