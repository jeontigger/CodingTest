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
int x[100001], y[100001];

void Inputs() {
	cin >> N;
	FOR(i, N)
		cin >> x[i] >> y[i];
}

void Solution() {
	int minx, miny, maxx, maxy;
	minx = miny = 10001;
	maxx = maxy = -10001;
	FOR(i, N) {
		minx = min(minx, x[i]);
		maxx = max(maxx, x[i]);
		miny = min(miny, y[i]);
		maxy = max(maxy, y[i]);
	}

	cout << (maxx - minx) * (maxy - miny);
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