#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

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

vector<vector<int>>scc;
vector<int>ids;
vector<int> finished;
vector<vector<int>> edges;
stack<int> s;
int id = 0;

int DFS(int curNode) {
	ids[curNode] = ++id;

	int parent = ids[curNode];
	s.push(curNode);

	for (int i = 0; i < edges[curNode].size(); i++) {
		int nextNode = edges[curNode][i];

		if (ids[nextNode] == 0) {
			parent = min(parent, DFS(nextNode));
		}
		else if (!finished[nextNode]) {
			parent = min(parent, ids[nextNode]);
		}
	}

	if (parent == ids[curNode]) {
		vector<int> v;
		while (true) {
			int topNode = s.top();
			s.pop();
			v.push_back(topNode);
			finished[topNode] = true;
			if (topNode == curNode) break;
		}
		scc.push_back(v);
	}

	return parent;
}

bool cmpv(const vector<int>& v1, const vector<int>& v2) {
	return *min_element(v1.begin(), v1.end()) < *min_element(v2.begin(), v2.end());
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	edges.resize(V + 1);
	ids.resize(V + 1);
	finished.resize(V + 1);

	int f, t;
	for (int i = 0; i < E; i++) {
		cin >> f >> t;
		edges[f].push_back(t);
	}

	for (int i = 1; i < V + 1; i++) {
		if (ids[i] == 0)DFS(i);
	}

	sort(scc.begin(), scc.end(), cmpv);
	for (int i = 0; i < scc.size(); i++) {
		sort(scc[i].begin(), scc[i].end());
	}

	printf("%d\n", scc.size());
	for (int i = 0; i < scc.size(); i++) {
		for (int j = 0; j < scc[i].size(); j++) {
			printf("%d ", scc[i][j]);
		}
		printf("-1\n");
	}

	return 0;
}