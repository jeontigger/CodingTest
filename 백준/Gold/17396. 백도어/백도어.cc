#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <set>

using namespace std;

#define INF 1e12

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

struct Edge {
	int to;
	long long w;
};

struct cmp {
	bool operator()(const Edge& e1, const Edge& e2) {
		return e1.w > e2.w;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> wards(N);
	for (int i = 0; i < N; i++) {
		cin >> wards[i];
	}

	vector<vector<Edge>> edges(N);
	int v1, v2, w;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> w;
		edges[v1].push_back({ v2, w });
		edges[v2].push_back({ v1, w });
	}

	priority_queue<Edge, vector<Edge>, cmp> pq;
	vector<int> dist(N, INF);
	pq.push({ 0, 0 });
	dist[0] = 0;

	while (!pq.empty()) {
		Edge edge = pq.top();
		pq.pop();

		if (edge.to == N - 1) {
			cout << edge.w;
			return 0;
		}

		if (wards[edge.to]) continue;
		wards[edge.to] = true;
		//cout << edge.to << " ";

		for (int i = 0; i < edges[edge.to].size(); i++) {
			int next = edges[edge.to][i].to;
			int weight = edges[edge.to][i].w;

			if (dist[next] > dist[edge.to] + weight)
			{
				dist[next] = dist[edge.to] + weight;
				pq.push({ next, weight + edge.w });
			}
		}
	}

	cout << -1;
	return 0;
}