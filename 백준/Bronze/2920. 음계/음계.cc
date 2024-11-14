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

	int n, prev;
	prev = 0;

	cin >> n;
	prev = n;

	bool asc = false, des = false;
	for (int i = 1; i < 8; i++) {
		cin >> n;
		if (prev > n) {
			des = true;
		}
		else if (prev < n) {
			asc = true;
		}
		prev = n;
	}

	if (asc && des) {
		cout << "mixed";
	}
	else if (asc) {
		cout << "ascending";
	}
	else {
		cout << "descending";
	}



	return 0;
}

