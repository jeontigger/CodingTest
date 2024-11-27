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
	cout << '\n';
}

template<typename T>
void PrintVec(const vector<vector<T>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<int>>minpq;
unordered_map<int, int> cnts;

void Insert(int n) {
	maxpq.push(n);
	minpq.push(n);
	cnts[n]++;
}

void Delete(int delta) {
	while (!maxpq.empty() && cnts[maxpq.top()] == 0) {
		maxpq.pop();
	}
	while (!minpq.empty() && cnts[minpq.top()] == 0) {
		minpq.pop();
	}

	if (delta == 1) {
		// 최댓값 삭제
		if (!maxpq.empty()) {
			int num = maxpq.top();
			maxpq.pop();
			cnts[num]--;
		}
	}
	else {
		// 최솟값 삭제
		if (!minpq.empty()) {
			int num = minpq.top();
			minpq.pop();
			cnts[num]--;
		}
	}

	while (!maxpq.empty() && cnts[maxpq.top()] == 0) {
		maxpq.pop();
	}
	while (!minpq.empty() && cnts[minpq.top()] == 0) {
		minpq.pop();
	}

}

void Print() {
	if (maxpq.empty() || minpq.empty()) {
		cout << "EMPTY\n";
	}
	else {
		cout << maxpq.top() << ' ' << minpq.top() << '\n';
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cnts.clear();
		while (N--) {
			char c;
			cin >> c;
			int n;
			cin >> n;
			if (c == 'I') {
				Insert(n);
			}
			else {
				Delete(n);
			}
		}

		Print();

		minpq = priority_queue<int, vector<int>, greater<int>>();
		maxpq = priority_queue<int>();

	}

	return 0;
}