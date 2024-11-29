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

vector<int> visited;
vector<vector<int>> edges;
vector<int> parents;

void FindParents(int curNode = 1) {

	for (int i = 0; i < edges[curNode].size(); i++) {
		int next = edges[curNode][i];
		if (visited[next])continue;
		visited[next] = true;
		parents[next] = curNode;
		FindParents(next);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	edges.resize(N + 1);
	visited.resize(N + 1);
	parents.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}

	FindParents();

	for (int i = 2; i <= N; i++) {
		cout << parents[i] << ' ';
	}


	return 0;
}