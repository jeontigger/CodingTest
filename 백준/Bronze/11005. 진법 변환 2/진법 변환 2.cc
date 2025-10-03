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
int before;

void Inputs() {
	cin >> before >> N;
}

int Change(char c) {
	int ret = 0;

	if (isalpha(c)) {
		ret = c - 'A' + 10;
	}
	else {
		ret = c - '0';
	}

	return ret;
}

char Change(int n) {
	char ret = 0;
	if (n < 10) {
		ret = '0' + n;
	}
	else {
		ret = 'A' + n - 10;
	}

	return ret;
}

void Solution() {
	string ret;
	while (before > 0) {
		int remain = before % N;
		char c = Change(remain);
		before /= N;

		ret = c + ret;
	}

	cout << ret;
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