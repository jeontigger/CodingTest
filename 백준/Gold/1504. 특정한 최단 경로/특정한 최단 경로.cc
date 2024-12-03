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

int N, E;
vector<vector<Edge>> edges;

int Dijkstra(int start, int end) {
	vector<int> dist(N + 1, INF);
	dist[start] = 0;

	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ start, 0 });


	while (!pq.empty()) {
		Edge edge = pq.top();
		pq.pop();

		if (dist[edge.to] > edge.w) continue;

		for (int i = 0; i < edges[edge.to].size(); i++) {
			int next = edges[edge.to][i].to;
			int cost = edges[edge.to][i].w + edge.w;

			if (dist[next] > cost) {
				dist[next] = cost;
				pq.push({ next, cost });
			}
		}
	}

	return dist[end];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E;
	edges.resize(N + 1);
	for (int i = 0; i < E; i++) {
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		edges[v1].push_back({ v2, c });
		edges[v2].push_back({ v1, c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	int d1 = Dijkstra(1, v1);
	int d2 = Dijkstra(1, v2);

	int common = Dijkstra(v1, v2);

	int d1_2 = Dijkstra(v2, N);
	int d2_1 = Dijkstra(v1, N);

	if ((d1 == d2 && d1 == INF) || (d1_2 == d2_1 && d1_2 == INF) || common == INF) {
		cout << -1;
		return 0;
	}

	int res = common;
	d1 + d1_2 > d2 + d2_1 ? res += d2 + d2_1 : res += d1 + d1_2;
	cout << res;

	return 0;
}