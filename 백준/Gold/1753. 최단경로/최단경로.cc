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
	int cost;
};

struct cmp {
	bool operator()(const Edge& e1, const Edge& e2) {
		return e1.cost != e2.cost ? e1.cost > e2.cost : e1.to < e2.to;
	}
};

void Dijkstra(const vector<vector<Edge>>& edges, int K, int V) {
	vector<int> dist(V + 1, INF);
	dist[K] = 0;

	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ K, 0 });

	while (!pq.empty()) {
		Edge cur = pq.top();
		pq.pop();

		if (dist[cur.to] < cur.cost)continue;

		for (int i = 0; i < edges[cur.to].size(); i++) {
			int next = edges[cur.to][i].to;
			int nextCost = cur.cost + edges[cur.to][i].cost;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF ";
		}
		else {
			cout << dist[i] << ' ';
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K;
	cin >> V >> E >> K;

	vector<vector<Edge>> edges(V + 1);
	for (int i = 0; i < E; i++) {
		int f, t, c;
		cin >> f >> t >> c;
		edges[f].push_back({ t, c });
	}

	Dijkstra(edges, K, V);


	return 0;
}
