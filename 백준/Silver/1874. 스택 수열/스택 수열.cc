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

	int N;
	cin >> N;

	stack<int> s;

	vector<char> res;

	int num = 1;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		while (num <= n) {
			res.push_back('+');
			s.push(num++);
		}


		if (s.empty()) {
			cout << "NO";
			return 0;
		}

		while (s.top() != n) {
			res.push_back('-');
			s.pop();

			if (s.empty()) {
				cout << "NO";
				return 0;
			}
		}
		res.push_back('-');
		s.pop();


	}

	PrintVec(res);

	return 0;
}