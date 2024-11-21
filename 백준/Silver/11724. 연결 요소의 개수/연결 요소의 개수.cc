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
	cout << endl;
}

template<typename T>
void PrintVec(const vector<vector<T>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

void Connected(vector<vector<int>>& edges, vector<bool>& visited, int start) {

	for (int i = 0; i < edges[start].size(); i++) {
		int next = edges[start][i];
		if (visited[next]) continue;
		visited[next] = true;
		Connected(edges, visited, next);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> edges(N + 1);

	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}

	vector<bool> visited(N + 1);
	int cnt = 0;
	for (int i = 1; i < N + 1; i++) {
		if (visited[i]) continue;
		cnt++;
		visited[i] = true;
		Connected(edges, visited, i);
	}

	cout << cnt;

	return 0;
}