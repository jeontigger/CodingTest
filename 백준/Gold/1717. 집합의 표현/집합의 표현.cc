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

int N, M;
vector<int> roots;

int Find(int n) {
	if (roots[n] == n) {
		return n;
	}
	else {
		return roots[n] = Find(roots[n]);
	}
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	roots[max(a, b)] = min(a, b);
}

void Inputs() {
	cin >> N >> M;

	roots.resize(N + 1);
	FOR(i, N + 1) {
		roots[i] = i;
	}

	FOR(i, M) {
		int c, a, b;
		cin >> c >> a >> b;
		if (c == 0) {
			Union(a, b);
		}
		else {
			if (Find(a) == Find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

}


void Solution() {

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