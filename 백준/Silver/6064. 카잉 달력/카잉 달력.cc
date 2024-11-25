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

long long gcd(long long a, long long b) {
	long long c = b;
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
		long long N, M, x, y;
		cin >> N >> M >> x >> y;
		if (y == M)
			y = 0;

		long long least = lcm(N, M);
		bool noway = true;
		for (int i = x; i <= least; i += N) {
			if (i % M == y) {
				cout << i << ' ';
				noway = false;
				break;
			}
		}

		if (noway) {
			cout << -1 << ' ';
		}

	}


	return 0;
}