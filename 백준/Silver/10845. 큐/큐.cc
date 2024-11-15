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

	queue<int> q;

	for (int i = 0; i < N; i++) {
		string com;
		cin >> com;

		int n;
		if (com == "push") {
			cin >> n;
			q.push(n);
		}

		if (com == "pop") {
			if (q.empty()) {
				cout << -1 << " ";
			}
			else {
				cout << q.front() << " ";
				q.pop();
			}
		}

		if (com == "size") {
			cout << q.size() << " ";
		}

		if (com == "empty") {
			cout << q.empty() << " ";
		}

		if (com == "front") {
			if (q.empty()) {
				cout << -1 << " ";
			}
			else {
				cout << q.front() << " ";
			}
		}

		if (com == "back") {
			if (q.empty()) {
				cout << -1 << " ";
			}
			else {
				cout << q.back() << " ";
			}
		}


	}
	return 0;
}