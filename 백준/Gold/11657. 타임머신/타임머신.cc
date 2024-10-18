#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1e15

struct Edge {
	int from;
	int to;
	int weight;
};

void Input(vector<Edge>& edges, int& n) {
	int M;
	cin >> n >> M;

	for (int i = 0; i < M; i++) {
		int f, t, w;
		cin >> f >> t >> w;
		edges.push_back({ f - 1, t - 1, w });
	}
}

void BellmanFord(const vector<Edge>& edges, int n) {
	vector<long long> dist(n, INF);
	dist[0] = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < edges.size(); j++) {
			long long from = edges[j].from;
			long long to = edges[j].to;
			long long weight = edges[j].weight;
			long long cost = dist[from] + weight;

			if (dist[from] == INF) continue;
			if (cost < dist[to]) {
				if (i == n) {
					cout << -1 << endl;
					return;
				}
				else {
					dist[to] = cost;
				}
			}
		}
	}

	for (int i = 1; i < n; i++) {
		if (dist[i] == INF) {
			cout << -1 << endl;
		}
		else {
			cout << dist[i] << endl;
		}
	}
}

int main() {

	vector<Edge> edges;
	int n;
	Input(edges, n);

	BellmanFord(edges, n);

	return 0;
}