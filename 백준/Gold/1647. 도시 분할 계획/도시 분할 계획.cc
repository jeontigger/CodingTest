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
	int v1;
	int v2;
	int c;
};

struct cmp {
	bool operator()(const Edge& e1, const Edge& e2) {
		return e1.c > e2.c;
	}
};

vector<int> parents;

int Find(int x) {
	if (x == parents[x])
		return x;
	else
		return parents[x] = Find(parents[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	parents[a] = b;
}

void Kruskal(const vector<Edge>& edges) {

	priority_queue<Edge, vector<Edge>, cmp> pq;

	for (int i = 0; i < edges.size(); i++) {
		pq.push(edges[i]);
	}

	int res = 0;
	int lastCost = 0;

	while (!pq.empty()) {
		Edge edge = pq.top();
		pq.pop();

		int v1 = edge.v1;
		int v2 = edge.v2;
		int c = edge.c;

		if (Find(v1) == Find(v2))continue;

		Union(v1, v2);
		res += c;
		lastCost = c;
	}

	cout << res - lastCost;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<Edge> edges(M);

	for (int i = 0; i < M; i++) {
		cin >> edges[i].v1 >> edges[i].v2 >> edges[i].c;
	}

	parents.resize(N + 1);
	for (int i = 0; i < parents.size(); i++) {
		parents[i] = i;
	}

	Kruskal(edges);

	return 0;
}