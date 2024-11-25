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

int gcd(int a, int b) {
	int c = b;
	while (c != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int res = -1;

		int limit = lcm(M, N);
		for (int i = x; i <= limit; i += M) {
			int mod = i % N;
			if (mod == 0) mod = N;
			if (mod == y) {
				res = i;
				break;
			}
		}
		cout << res << ' ';

	}

	return 0;
}