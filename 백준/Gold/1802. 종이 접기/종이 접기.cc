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

string paper;
void Inputs() {
	cin >> paper;
}

bool DC(int left, int right) {
	if (left == right) return true;

	int half = (left + right) / 2;
	int halfsize = (right - left) / 2;
	string l = paper.substr(0, halfsize);
	string r = paper.substr(half + 1, halfsize);
	reverse(r.begin(), r.end());
	for (int i = 0; i < r.size(); i++) {
		if (r[i] == '1') {
			r[i] = '0';
		}
		else {
			r[i] = '1';
		}
	}
	if (l == r) {
		return DC(left, half - 1) && DC(half + 1, right);
	}
	else {
		return false;
	}

}

void Solution() {
	int n = paper.size();
	if (DC(0, n - 1))
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}