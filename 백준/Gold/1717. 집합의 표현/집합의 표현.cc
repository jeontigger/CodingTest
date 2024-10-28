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

class UF {
public:

	UF(int n) {
		root.resize(n + 1);
		for (int i = 0; i < root.size(); i++) {
			root[i] = i;
		}
	}

	int Find(int n) {
		while (n != root[n]) {
			n = root[n];
		}

		return n;
	}

	void Union(int a, int b) {
		a = Find(a);
		b = Find(b);

		if (a == b) return;

		root[b] = a;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	UF uf(n);
	int c, v1, v2;
	for (int i = 0; i < m; i++) {
		cin >> c >> v1 >> v2;
		if (c == 0) {
			uf.Union(v1, v2);
		}
		else {
			v1 = uf.Find(v1);
			v2 = uf.Find(v2);
			if (v1 == v2) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}


	return 0;
}