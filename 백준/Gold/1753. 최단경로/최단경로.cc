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
	int to;
	int w;
};

struct cmp {
	bool operator()(const Edge& e1, const Edge& e2) {
		return e1.w > e2.w;
	}
};

int V, E, K;
vector<vector<Edge>> edges;

void Dijkstra(int start) {
	priority_queue<Edge, vector<Edge>, cmp>pq;
	pq.push({ start, 0 });
	vector<int> dist(V + 1, INF);
	dist[start] = 0;

	while (!pq.empty()) {
		Edge edge = pq.top();
		pq.pop();

		if (dist[edge.to] < edge.w) continue;

		for (int i = 0; i < edges[edge.to].size(); i++) {
			int next = edges[edge.to][i].to;
			int cost = edges[edge.to][i].w + edge.w;
			if (dist[next] > cost) {
				dist[next] = cost;
				pq.push({ next, cost });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << '\n';
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E >> K;
	edges.resize(V + 1);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({ v, w });
	}

	Dijkstra(K);

	return 0;
}
