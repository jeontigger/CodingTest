#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> maps(n + 1, vector<int>(n + 1, INF));

	int f, t, w;
	for (int i = 0; i < m; i++) {
		cin >> f >> t >> w;
		maps[f][t] = min(maps[f][t], w);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k) continue;
				maps[j][k] = min(maps[j][k], maps[j][i] + maps[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (maps[i][j] == INF) {
				cout << 0 << " ";
			}
			else {
				cout << maps[i][j] << " ";
			}
		}
		cout << endl;
	}
	//PrintVec(maps);

	return 0;
}