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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));
	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}

	for (int k = 1; k < N + 1; k++) {
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int minValue = INF;
	int res = -1;
	for (int i = 1; i < N + 1; i++) {
		int sum = 0;
		for (int j = 1; j < N + 1; j++) {
			sum += graph[i][j];
		}
		if (minValue > sum) {
			minValue = sum;
			res = i;
		}
	}

	cout << res;
	return 0;
}