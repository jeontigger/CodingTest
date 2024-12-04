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

string Bomb(string& origin, const string& bomb) {

	string s;
	for (int i = 0; i < origin.size(); i++) {
		s.push_back(origin[i]);


		while (s.size() >= bomb.size() && s.substr(s.size() - bomb.size(), s.size()) == bomb) {
			s.resize(s.size() - bomb.size());
		}
	}

	if (s == "") {
		s = "FRULA";
	}

	return s;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string origin, bomb;
	cin >> origin >> bomb;

	cout << Bomb(origin, bomb);

	return 0;
}
