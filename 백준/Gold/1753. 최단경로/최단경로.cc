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
		return e1.weight != e2.weight ? e1.weight > e2.weight : e1.to > e2.to;
	}
};

void Input(vector<vector<Edge>>& edges, int& start) {
	int V, E;
	cin >> V >> E >> start;
	start--;

	edges.resize(V);
	for (int i = 0; i < E; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		edges[from - 1].push_back({ w, to - 1 });
	}
}

void Dijkstra(vector<vector<Edge>>& edges, int& start) {

	vector<int> dist(edges.size(), INF);
	priority_queue < Edge, vector<Edge>, cmp> pq;

	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		Edge edge = pq.top();
		pq.pop();

		int from = edge.to;
		int weight = edge.weight;

		if (dist[from] < weight) continue;



		for (int i = 0; i < edges[from].size(); i++) {
			int to = edges[from][i].to;
			int w = edges[from][i].weight;
			if (dist[to] > weight + w) {
				dist[to] = w + weight;
				pq.push({ w + weight, to });
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
