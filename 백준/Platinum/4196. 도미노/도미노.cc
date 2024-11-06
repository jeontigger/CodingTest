
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
vector<int> ids;
vector<int> finished;
stack<int> s;
int id;
vector<vector<int>> scc;
vector<int> indegree;
vector<int> sccGroup;

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
		while (!s.empty()) {
			int topNode = s.top();
			s.pop();
			finished[topNode] = true;
			v.push_back(topNode);
			sccGroup[topNode] = scc.size();
			if (topNode == curNode) break;
		}
		scc.push_back(v);
	}

	return parent;
}

void MakeIndegree(int N) {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 0; j < edges[i].size(); j++) {
			int cur = i;
			int next = edges[i][j];
			if (sccGroup[cur] != sccGroup[next]) {
				indegree[sccGroup[next]]++;
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int N, M;
	while (T) {
		T--;
		cin >> N >> M;

		// Init
		edges.clear();
		edges.resize(N + 1);
		ids.clear();
		ids.resize(N + 1);
		finished.clear();
		finished.resize(N + 1);
		scc.clear();
		indegree.clear();
		indegree.resize(N + 1);
		sccGroup.clear();
		sccGroup.resize(N + 1);
		id = 0;

		int f, t;
		for (int i = 0; i < M; i++) {
			cin >> f >> t;
			edges[f].push_back(t);
		}

		for (int i = 1; i <= N; i++) {
			if (ids[i] == 0)DFS(i);
		}

		MakeIndegree(N);
		//PrintVec(ids);
		//PrintVec(indegree);
		//PrintVec(sccGroup);

		int cnt = 0;
		for (int i = 0; i < scc.size(); i++) {
			if (indegree[i] == 0)cnt++;
		}
		cout << cnt << " ";
	}


	return 0;
}