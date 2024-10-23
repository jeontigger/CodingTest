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

void DFS(vector<vector<int>>& nodes, vector<int>& parents, int curNode) {

	for (int i = 0; i < nodes[curNode].size(); i++) {
		int nextNode = nodes[curNode][i];
		if (parents[nextNode])continue;

		parents[nextNode] = curNode;

		DFS(nodes, parents, nextNode);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> nodes(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int r1, r2;
		cin >> r1 >> r2;
		nodes[r1].push_back(r2);
		nodes[r2].push_back(r1);
	}

	vector<int> parents(n + 1);
	parents[1] = 1;
	DFS(nodes, parents, 1);

	for (int i = 2; i < parents.size(); i++) {
		printf("%d ", parents[i]);
	}

	return 0;
}