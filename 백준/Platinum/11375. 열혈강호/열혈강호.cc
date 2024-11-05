
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

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

vector<vector<int>> edges;
vector<bool> visited;
vector<int> parents;

bool DFS(int curNode) {

	for (int i = 0; i < edges[curNode].size(); i++) {
		int nextNode = edges[curNode][i];
		if (visited[nextNode])continue;
		visited[nextNode] = true;

		if (parents[nextNode] == 0 || DFS(parents[nextNode])) {
			parents[nextNode] = curNode;
			//cout << nextNode << " ";

			return true;
		}
	}

	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	edges.resize(N + 1);
	parents.resize(M + 1);

	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		edges[i + 1].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> edges[i + 1][j];
		}
	}

	//PrintVec(edges);

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		visited.clear();
		visited.resize(M + 1, false);
		if (DFS(i)) {
			//cout << "DFS " << i << endl;
			cnt++;
		}
	}

	cout << cnt;


	return 0;
}