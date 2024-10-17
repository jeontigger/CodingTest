#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1e9

struct Edge {
	int weight;
	int to;
};

struct cmp {
	bool operator()(const Edge& e1, const Edge& e2) {
		return e1.weight > e2.weight;
	}
};

void Input(vector<vector<Edge>>& edges, int& v1, int& v2) {
	int V, E;
	cin >> V >> E;

	edges.resize(V);
	for (int i = 0; i < E; i++) {
		int n1, n2, w;
		cin >> n1 >> n2 >> w;
		edges[n1 - 1].push_back({ w, n2 - 1 });
		edges[n2 - 1].push_back({ w, n1 - 1 });
	}

	cin >> v1 >> v2;
	v1--;
	v2--;
}

int Dijkstra(const vector<vector<Edge>>& edges, int start, int end) {
	priority_queue<Edge, vector<Edge>, cmp>pq;
	vector<int> dist(edges.size(), INF);

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int curNode = pq.top().to;
		int curWeight = pq.top().weight;
		pq.pop();

		if (dist[curNode] < curWeight) continue;

		for (int i = 0; i < edges[curNode].size(); i++) {
			int toNode = edges[curNode][i].to;
			int toWeight = edges[curNode][i].weight;
			int cost = curWeight + toWeight;

			if (cost < dist[toNode]) {
				dist[toNode] = cost;
				pq.push({ cost, toNode });
			}
		}
	}

	return dist[end];
}

int main() {

	vector<vector<Edge>> edges;
	int v1, v2;

	Input(edges, v1, v2);

	int dist = 0, r1 = 0, r2 = 0;

	r1 += Dijkstra(edges, 0, v1);
	if (r1 >= INF)
	{
		cout << -1 << endl;
		return 0;
	}
	r2 += Dijkstra(edges, 0, v2);

	if (r2 >= INF)
	{
		cout << -1 << endl;
		return 0;
	}
	dist += Dijkstra(edges, v1, v2);
	if (dist >= INF)
	{
		cout << -1 << endl;
		return 0;
	}

	r2 += Dijkstra(edges, v1, edges.size() - 1);
	if (r2 >= INF)
	{
		cout << -1 << endl;
		return 0;
	}
	r1 += Dijkstra(edges, v2, edges.size() - 1);
	if (r1 >= INF)
	{
		cout << -1 << endl;
		return 0;
	}

	dist += min(r1, r2);

	cout << dist << endl;
	return 0;
}