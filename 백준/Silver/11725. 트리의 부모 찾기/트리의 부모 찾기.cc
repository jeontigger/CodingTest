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

int N;
vector<vector<int>> edges;
vector<int> parents;
void SetParents() {
	queue<int> q;
	vector<int> visited(N + 1);

	int parent = 1;
	q.push(parent);
	visited[parent] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur][i];
			if (!visited[next]) {
				visited[next] = true;
				parents[next] = cur;
				q.push(next);
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	edges.resize(N + 1);
	parents.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}

	SetParents();

	for (int i = 2; i < N + 1; i++) {
		cout << parents[i] << '\n';
	}

	return 0;
}
