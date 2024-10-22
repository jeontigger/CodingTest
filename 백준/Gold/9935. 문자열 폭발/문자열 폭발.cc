#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

#define INF 1e9


void PrintVec(const vector<int>& v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

void PrintVec(const vector<vector<int>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string origin, bomb;
	cin >> origin;
	cin >> bomb;

	string s;

	for (int i = 0; i < origin.size(); i++) {
		s += origin[i];

		if (s.size() >= bomb.size()) {
			if (s.substr(s.size() - bomb.size(), bomb.size()) == bomb) {
				s.resize(s.size() - bomb.size());
			}
		}
	}

	if (s.size() == 0) {
		cout << "FRULA" << endl;
	}
	else {
		cout << s << endl;
	}
}