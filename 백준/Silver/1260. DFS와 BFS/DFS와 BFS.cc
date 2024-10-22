#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

#define INF 1e9


void PrintVec(const vector<int>& v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

void PrintVec(const vector<vector<int>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

struct Node {
	int from;
	int to;
};

void DFS(int N, int idx, const vector<vector<int>>& graph, vector<bool>& visited) {

	cout << idx << " ";
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;

		if (graph[idx][i] == 1) {
			visited[i] = true;
			DFS(N, i, graph, visited);
		}
	}
}

void BFS(int start, const vector<vector<int>>& graph) {
	queue<int> q;
	q.push(start);
	vector<bool>visited(graph.size());
	visited[0] = true;
	visited[start] = true;

	while (!q.empty()) {
		int idx = q.front();
		cout << idx << " ";
		q.pop();

		for (int i = 0; i < graph.size(); i++) {
			if (visited[i]) continue;
			if (graph[idx][i] == 1) {
				visited[i] = true;
				q.push(i);
			}
		}

	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, start;
	cin >> N >> M >> start;
	start;

	vector<vector<int>> graph(N + 1, vector<int>(N + 1));

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		graph[from][to] = 1;
		graph[to][from] = 1;
	}

	vector<bool> visited(N + 1);
	visited[start] = true;
	visited[0] = true;
	DFS(N + 1, start, graph, visited);
	cout << endl;

	BFS(start, graph);

	return 0;
}