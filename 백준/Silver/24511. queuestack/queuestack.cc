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
#include <iomanip>
#include <cassert>
#include <cstring>
#include <list>

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
#define FOR(idx, limit) for(int idx = 0; idx < limit; idx++)

int N;
vector<int> type;
queue<int> q;
void Inputs() {
	cin >> N;

	type.resize(N);
	FOR(i, N) {
		cin >> type[i];
	}


	stack<int> s;
	FOR(i, N) {
		int num;
		cin >> num;
		if (type[i] == 0) {
			s.push(num);
		}
	}

	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}

	cin >> N;
	FOR(i, N) {
		int n;
		cin >> n;
		q.push(n);
	}
}


void Solution() {

	FOR(i, N) {
		cout << q.front() << ' ';
		q.pop();
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	//cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}