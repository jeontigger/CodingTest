#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 100000000

struct Edge {
	int weight;
	int to;
};

struct cmp {
	bool operator()(const Edge& e1, const Edge& e2) {
		return e1.weight > e2.weight;
	}
};

void Input(vector<vector<Edge>>& edges, int& start) {
	int V, E;
	cin >> V >> E >> start;
	start--;

	edges.resize(V);
	for (int i = 0; i < E; i++) {
		int f, t, w;
		cin >> f >> t >> w;
		edges[f - 1].push_back({ w, t - 1 });
	}

}

void Dijkstra(vector<vector<Edge>>& edges, int start) {

	priority_queue<Edge, vector<Edge>, cmp> pq;
	vector<int> dist(edges.size(), INF);

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int curNode = pq.top().to;
		int curWeight = pq.top().weight;
		pq.pop();

		if (dist[curNode] < curWeight) continue;

		for (Edge& edge : edges[curNode]) {
			int toNode = edge.to;
			int toWeight = edge.weight;
			int cost = toWeight + curWeight;

			if (dist[toNode] > cost) {
				dist[toNode] = cost;
				pq.push({ cost, toNode });
			}
		}
	}

	for (int i : dist) {
		if (i == INF) {
			cout << "INF" << endl;
		}
		else {
			cout << i << endl;
		}
	}
}

int main() {

	vector<vector<Edge>> edges;
	int start;
	Input(edges, start);
	Dijkstra(edges, start);


	return 0;
}