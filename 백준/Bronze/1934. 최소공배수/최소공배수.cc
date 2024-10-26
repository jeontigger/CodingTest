#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

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

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

struct Data {
	int paper;
	int meet;
};

bool cmp(const Data& d1, const Data& d2) {
	return d1.paper < d2.paper;
}

int gcd(int a, int b) {

	int r = a;
	while (r != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int lcm(int a, int b, int g) {
	return a * b / g;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T) {
		T--;

		int a, b;
		cin >> a >> b;
		int g = gcd(a, b);
		cout << lcm(a, b, g) << endl;


	}

	return 0;
}