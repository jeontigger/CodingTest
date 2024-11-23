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

void Insert(int n, priority_queue<int>& maxpq, priority_queue<int, vector<int>, greater<int>>& minpq, unordered_map<int, int>& m) {
	maxpq.push(n);
	minpq.push(n);
	m[n]++;
}

void Delete(int type, priority_queue<int>& maxpq, priority_queue<int, vector<int>, greater<int>>& minpq, unordered_map<int, int>& m) {
	// 1은 최대값 제거, -1은 최소값 제거
	if (type == 1) {
		while (!maxpq.empty() && m[maxpq.top()] == 0) {
			maxpq.pop();
		}

		if (maxpq.empty()) return;
		int curNum = maxpq.top();
		m[curNum]--;
		maxpq.pop();
	}
	else {
		while (!minpq.empty() && m[minpq.top()] == 0) {
			minpq.pop();
		}

		if (minpq.empty()) return;
		int curNum = minpq.top();
		m[curNum]--;
		minpq.pop();
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {

		int k;
		cin >> k;

		priority_queue<int> maxpq;
		priority_queue<int, vector<int>, greater<int>> minpq;
		unordered_map<int, int> m;
		while (k--) {
			char c;
			int n;
			cin >> c >> n;

			if (c == 'I') {
				Insert(n, maxpq, minpq, m);
			}
			else if (c == 'D') {
				Delete(n, maxpq, minpq, m);
			}
		}
		while (!maxpq.empty() && m[maxpq.top()] == 0) {
			maxpq.pop();
		}
		while (!minpq.empty() && m[minpq.top()] == 0) {
			minpq.pop();
		}
		if (maxpq.empty() || minpq.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << maxpq.top() << ' ' << minpq.top() << '\n';
		}


	}

	return 0;
}