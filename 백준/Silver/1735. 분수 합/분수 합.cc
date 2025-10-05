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

long long A1, B1, A2, B2;

void Inputs() {
	cin >> A1 >> B1 >> A2 >> B2;
}

long long gcd(long long a, long long b) {
	long long r = a;
	while (r != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

void Solution() {
	A1 *= B2;
	A2 *= B1;
	long long d = gcd(A1 + A2, B1 * B2);
	cout << (A1 + A2) / d << ' ' << B1 * B2 / d;
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