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

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

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

void DFS(vector<vector<int>>& edges, int curNode, vector<bool>& visited) {
	cout << curNode << ' ';

	for (int i = 0; i < edges[curNode].size(); i++) {
		int next = edges[curNode][i];
		if (visited[next]) continue;
		visited[next] = true;
		DFS(edges, next, visited);
	}
}
void BFS(vector<vector<int>>& edges, int start) {
	queue<int> q;
	q.push(start);

	vector<bool> visited(edges.size());
	visited[start] = true;

	while (!q.empty()) {
		int curNode = q.front();
		q.pop();
		cout << curNode << ' ';

		for (int i = 0; i < edges[curNode].size(); i++) {
			int nextNode = edges[curNode][i];
			if (visited[nextNode]) continue;
			visited[nextNode] = true;
			q.push(nextNode);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;
	vector<vector<int>> edges(N + 1);
	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}

	for (int i = 0; i < N + 1; i++) {
		sort(edges[i].begin(), edges[i].end());
	}

	vector<bool> visited(N + 1);
	visited[V] = true;
	DFS(edges, V, visited);
	cout << '\n';

	BFS(edges, V);


	return 0;
}