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

vector<bool> visited;
vector<vector<int>> edges;
vector<vector<int>> tree;
vector<int> childCnt;

void MakeTree(int idx) {
	for (int i = 0; i < edges[idx].size(); i++) {
		int next = edges[idx][i];
		if (visited[next]) continue;
		visited[next] = true;

		tree[idx].push_back(next);

		MakeTree(next);
	}
}

int Query(int idx) {

	int child = 0;
	for (int i = 0; i < tree[idx].size(); i++) {
		int next = tree[idx][i];
		child += Query(next);
	}

	return childCnt[idx] = child + 1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, R, Q;
	cin >> N >> R >> Q;

	edges.resize(N + 1);
	visited.resize(N + 1);
	tree.resize(N + 1);
	childCnt.resize(N + 1);
	int v1, v2;
	for (int i = 0; i < N - 1; i++) {
		cin >> v1 >> v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}

	visited[R] = true;
	MakeTree(R);

	Query(R);

	int q;
	while (Q--) {
		cin >> q;
		cout << childCnt[q] << " ";
	}

	return 0;
}