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
int first[10001], second[10001];

void Inputs() {
	FOR(i, 10000) {
		cin >> first[i] >> second[i];
		if (first[i] == 0 && second[i] == 0) {
			N = i;
			break;
		}
	}
}

bool IsFactor(int n1, int n2) {
	return (n2 % n1) == 0;
}

bool IsMultiple(int n1, int n2) {
	return IsFactor(n2, n1);
}

bool IsNeither(int n1, int n2) {
	return !IsFactor(n1, n2) && !IsFactor(n2, n1);
}

void Solution() {
	FOR(i, N) {
		if (IsFactor(first[i], second[i])) {
			cout << "factor\n";
		}
		else if (IsMultiple(first[i], second[i])) {
			cout << "multiple\n";
		}
		else if (IsNeither(first[i], second[i])) {
			cout << "neither\n";
		}
		else {
			cout << "???\n";
		}
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