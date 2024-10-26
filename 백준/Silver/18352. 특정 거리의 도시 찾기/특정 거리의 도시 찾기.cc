#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

#define INF 1e9

template<typename T>
void PrintVec(const vector<T>& v) {
	for (T i : v) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T>
void PrintVec(const vector<vector<T>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

struct Edge {
	int from;
	int to;
};

struct Data {
	int node;
	int len;
};

void Dijkstra(vector<vector<int>>& edges, int start, int K) {

	vector<int> dist(edges.size());
	dist[start] = 0;

	queue<Data> q;
	q.push({ start, 0 });


	while (!q.empty()) {
		Data data = q.front();
		int node = data.node;
		int len = data.len;

		q.pop();

		for (int i = 0; i < edges[node].size(); i++) {
			int nextNode = edges[node][i];
			int nextLen = len + 1;

			if (dist[nextNode] != 0)continue;

			dist[nextNode] = nextLen;
			q.push({ nextNode, nextLen });
		}
	}

	bool noExist = true;
	for (int i = 1; i < dist.size(); i++) {
		if (i == start) continue;
		if (dist[i] == K) {
			noExist = false;
			cout << i << " ";
		}
	}

	if (noExist) {
		cout << -1;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	vector<vector<int>> edges(N + 1);
	for (int i = 0; i < M; i++) {
		Edge edge;
		cin >> edge.from >> edge.to;
		edges[edge.from].push_back(edge.to);
	}

	Dijkstra(edges, X, K);

	return 0;
}