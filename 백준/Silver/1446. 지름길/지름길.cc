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

void Input(vector<vector<Edge>>& edges, int& target) {
	int N;
	cin >> N >> target;

	edges.resize(target + 1);
	for (int i = 0; i < N; i++) {
		int f, t, w;
		cin >> f >> t >> w;
		if (f > target || t > target) continue;
		edges[f].push_back({ w, t });
	}
}

void Dijkstra(vector<vector<Edge>>& edges, int target) {
	priority_queue<Edge, vector<Edge>, cmp>pq;
	vector<int> dist(target + 1, INF);

	for (int i = 0; i <= target; i++) {
		dist[i] = i;
		pq.push({ i, i });
	}

	while (!pq.empty()) {
		int curNode = pq.top().to;
		int curWeight = pq.top().weight;
		pq.pop();

		//if (dist[curNode] < curWeight) continue;

		for (int i = 0; i < edges[curNode].size(); i++) {
			int toNode = edges[curNode][i].to;
			int toWeight = edges[curNode][i].weight;
			int cost = curWeight + toWeight;

			for (int i = 0; i <= target - toNode; i++) {
				if (cost + i < dist[toNode + i]) {
					dist[toNode + i] = cost + i;
					pq.push({ cost + i , toNode + i });
				}
			}
		}
	}

	cout << dist[target];

}

int main() {

	vector<vector<Edge>> edges;
	int target;
	Input(edges, target);

	Dijkstra(edges, target);


	return 0;
}