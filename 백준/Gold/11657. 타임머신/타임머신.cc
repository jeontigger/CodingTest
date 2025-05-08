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

struct Edge {
	long long from;
	long long to;
	long long weight;
};
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<Edge> edges(M);
	for (int i = 0; i < M; i++) {
		cin >> edges[i].from >> edges[i].to >> edges[i].weight;
		edges[i].from;
		edges[i].to;
	}


	vector<long long> dist(N + 1, INF);
	dist[1] = 0;

	for (int i = 0; i < N - 1; i++) {
		for (const auto& edge : edges) {
			if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.weight) {
				dist[edge.to] = dist[edge.from] + edge.weight;
			}
		}
	}

	bool minus = false;
	for (const auto& edge : edges) {
		if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.weight) {
			minus = true;
		}
	}
	if (minus) {
		cout << -1;
		return 0;
	}
	else {
		for (int i = 2; i < N + 1; i++) {
			if (dist[i] == INF) {
				cout << -1 << ' ';
			}
			else {
				cout << dist[i] << ' ';
			}
		}
	}

	return 0;
}
