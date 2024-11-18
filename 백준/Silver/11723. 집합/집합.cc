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

	string str;
	int n;

	set<int>s;
	while (N--) {
		cin >> str;
		if (str == "add") {
			cin >> n;
			s.insert(n);
		}
		else if (str == "remove") {
			cin >> n;
			s.erase(n);
		}
		else if (str == "check") {
			cin >> n;
			if (s.find(n) == s.end()) {
				cout << 0 << " ";
			}
			else {
				cout << 1 << " ";
			}
		}
		else if (str == "toggle") {
			cin >> n;
			if (s.find(n) == s.end()) {
				s.insert(n);
			}
			else {
				s.erase(n);
			}
		}
		else if (str == "all") {
			for (int i = 1; i <= 20; i++) {
				s.insert(i);
			}
		}
		else if (str == "empty") {
			for (int i = 1; i <= 20; i++) {
				s.erase(i);
			}
		}
	}

	return 0;
}