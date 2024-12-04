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
	cout << '\n';
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

	int N, M;
	cin >> N >> M;
	vector<vector<int>> edges(N, vector<int>(N, INF));
	for (int i = 0; i < M; i++) {
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		v1--;
		v2--;
		edges[v1][v2] = min(edges[v1][v2], c);

	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (edges[i][j] == INF) {
				cout << "0 ";
			}
			else {
				cout << edges[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
