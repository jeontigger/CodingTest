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
	if (root[n] == n) {
		return n;
	}
	else {
		return root[n] = Find(root[n]);
	}
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	root[max(a, b)] = min(a, b);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	root.resize(n + 1);
	for (int i = 0; i < root.size(); i++) {
		root[i] = i;
	}
	int c, v1, v2;
	for (int i = 0; i < m; i++) {
		cin >> c >> v1 >> v2;
		if (c == 0) {
			Union(v1, v2);
		}
		else {
			if (Find(v1) == Find(v2)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}


	return 0;
}