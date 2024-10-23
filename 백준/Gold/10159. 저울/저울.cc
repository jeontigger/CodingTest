#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

#define INF 1e9


void PrintVec(const vector<int>& v) {
	for (int i : v) {
		printf("%d ", i);
	}
	printf("\n");
}

void PrintVec(const vector<vector<int>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

void DFS(vector<vector<vector<int>>>& nodes, vector<bool>& visited, int curNode, bool increase) {


	if (increase) {
		for (int i = 0; i < nodes[curNode][1].size(); i++) {
			int nextNode = nodes[curNode][1][i];

			if (visited[nextNode]) continue;
			visited[nextNode] = true;
			DFS(nodes, visited, nextNode, increase);
		}
	}
	else {
		for (int i = 0; i < nodes[curNode][0].size(); i++) {
			int nextNode = nodes[curNode][0][i];

			if (visited[nextNode]) continue;
			visited[nextNode] = true;
			DFS(nodes, visited, nextNode, increase);
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<vector<int>>> nodes(n + 1, vector<vector<int>>(2));
	for (int i = 0; i < m; i++) {
		int r1, r2;
		cin >> r1 >> r2;

		nodes[r1][0].push_back(r2);
		nodes[r2][1].push_back(r1);
	}

	for (int i = 1; i < n + 1; i++) {
		vector<bool> visited(n + 1);
		visited[i] = true;
		DFS(nodes, visited, i, false);
		DFS(nodes, visited, i, true);
		int cnt = 0;
		for (bool visit : visited) {
			if (visit) cnt++;
		}

		cout << n - cnt << " ";
	}



	return 0;
}