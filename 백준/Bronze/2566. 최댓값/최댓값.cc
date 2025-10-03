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

int map[10][10];

void Inputs() {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> map[i][j];
		}
	}
}

void Solution() {
	int maxValue = -1;
	int r, c;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (maxValue < map[i][j]) {
				maxValue = map[i][j];
				r = i;
				c = j;
			}
		}
	}

	cout << maxValue << '\n' << r << ' ' << c;
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