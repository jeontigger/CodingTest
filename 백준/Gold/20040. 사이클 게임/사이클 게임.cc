#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

using namespace std;

//#define INF 1e9

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

vector<int> roots;

int Find(int n) {
	if (n == roots[n]) {
		return n;
	}
	else {
		return roots[n] = Find(roots[n]);
	}
}

bool Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return true;

	roots[a] = b;

	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	roots.resize(n);
	for (int i = 0; i < n; i++) {
		roots[i] = i;
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		if (Union(a, b)) {
			cout << i + 1;
			return 0;
		}
	}

	cout << 0;

	return 0;
}