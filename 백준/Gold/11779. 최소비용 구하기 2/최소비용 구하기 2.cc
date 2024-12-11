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
	int c;
};

struct cmp {
	bool operator()(const Edge& e1, const Edge& e2) {
		return e1.c > e2.c;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<Edge>> edges(N + 1);
	for (int i = 0; i < M; i++) {
		int f, t, c;
		cin >> f >> t >> c;
		edges[f].push_back({ t, c });
	}

	int start, end;
	cin >> start >> end;

	priority_queue<Edge, vector<Edge>, cmp> pq;
	vector<int> dist(N + 1, INF);
	vector<int> path(N + 1);

	pq.push({ start, 0 });
	dist[start] = 0;
	while (!pq.empty()) {
		Edge edge = pq.top();
		pq.pop();

		if (dist[edge.to] < edge.c) continue;

		for (int i = 0; i < edges[edge.to].size(); i++) {
			int next = edges[edge.to][i].to;
			int cost = edges[edge.to][i].c + edge.c;

			if (dist[next] > cost) {
				dist[next] = cost;
				path[next] = edge.to;
				pq.push({ next, cost });
			}
		}
	}

	cout << dist[end] << '\n';

	vector<int> paths;
	int cur = end;
	while (path[cur] != 0) {
		paths.push_back(cur);
		cur = path[cur];
	}
	paths.push_back(start);

	cout << paths.size() << '\n';
	for (auto iter = paths.rbegin(); iter != paths.rend(); ++iter) {
		cout << *iter << ' ';
	}


	return 0;
}
