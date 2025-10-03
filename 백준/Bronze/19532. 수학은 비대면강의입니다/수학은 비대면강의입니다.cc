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

double a, b, c, d, e, f;
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

void Inputs() {
	cin >> a >> b >> c >> d >> e >> f;
}

void Solution() {
	double x, y, ratio;
	if (a == 0) {
		y = c / b;
		x = (f - e * y) / d;
	}
	else if (d == 0) {
		y = f / e;
		x = (c - b * y) / a;
	}
	else {
		b *= d;
		c *= d;
		e *= a;
		f *= a;
		a *= d;
		d = a;
		y = (c - f) / (b - e);
		x = (c - b * y) / a;
	}

	cout << (int)x << ' ' << (int)y;
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