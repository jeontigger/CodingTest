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

void Input(vector<vector<Edge>>& edges, int& start, int& end) {
	int N, M;
	cin >> N >> M;

	edges.resize(N);
	for (int i = 0; i < M; i++) {
		int f, t, w;
		cin >> f >> t >> w;
		edges[f - 1].push_back({ w, t - 1 });
	}

	cin >> start >> end;
	start--;
	end--;
}

void Dijkstra(vector<vector<Edge>>& edges, int start, int end) {

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
			int cost = toWeight + curWeight;

			if (cost < dist[toNode]) {
				dist[toNode] = cost;
				pq.push({ cost, toNode });
			}
		}
	}

	cout << dist[end];

}

int main() {

	vector<vector<Edge>> edges;
	int start, end;
	Input(edges, start, end);

	Dijkstra(edges, start, end);

	return 0;
}