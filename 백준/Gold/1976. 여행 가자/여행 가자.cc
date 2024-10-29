#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

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

vector<int> root;

int Find(int n) {
	if (n == root[n]) {
		return n;
	}
	else {
		return root[n] = Find(root[n]);
	}
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b)return;

	root[max(a, b)] = min(a, b);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	root.resize(n);
	for (int i = 0; i < n; i++) {
		root[i] = i;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int v;
			cin >> v;
			if (v == 1) {
				Union(i, j);
			}
		}
	}

	int v;
	cin >> v;
	v--;
	int prev = Find(v);
	for (int i = 1; i < m; i++) {
		cin >> v;
		v--;
		if (prev != Find(v)) {
			cout << "NO" << endl;
			return 0;
		}
		else {
			prev = Find(v);
		}
	}

	cout << "YES" << endl;

	return 0;
}