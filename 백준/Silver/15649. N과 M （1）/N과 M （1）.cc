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
		//cout << i << " ";
		printf("%d ", i);
	}
	printf("\n");
}

void PrintVec(const vector<vector<int>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

void DFS(vector<int>& logs, int N, int M, int idx, vector<bool>& visited) {
	if (logs.size() == M) {
		PrintVec(logs);
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i])continue;

		visited[i] = true;
		logs.push_back(i);
		DFS(logs, N, M, i, visited);
		logs.pop_back();
		visited[i] = false;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> logs;
	vector<bool> visited(N + 1);
	visited[0] = true;

	DFS(logs, N, M, 1, visited);


	return 0;
}