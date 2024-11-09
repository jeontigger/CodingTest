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

vector<int> finished;
vector<int> visited;
vector<int> parents;
vector<vector<int>> edges;
vector<vector<int>> scc;
vector<int> costs;
stack<int> s;
int id = 0;
int sum = 0;

int DFS(int curNode) {

	parents[curNode] = ++id;

	int parent = parents[curNode];

	s.push(curNode);

	for (int i = 0; i < edges[curNode].size(); i++) {
		int nextNode = edges[curNode][i];
		if (parents[nextNode] == 0) {
			parent = min(parent, DFS(nextNode));
		}
		else if (!finished[nextNode]) {
			parent = min(parent, parents[nextNode]);
		}
	}

	if (parent == parents[curNode]) {

		vector<int> v;
		int minValue = INF;
		while (true) {
			int topNode = s.top();
			s.pop();
			v.push_back(topNode);
			finished[topNode] = true;
			minValue = min(minValue, costs[topNode]);

			if (topNode == curNode) break;
		}
		sum += minValue;
		scc.push_back(v);
	}

	return parent;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	costs.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> costs[i];
	}

	edges.resize(N);
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '1') {
				edges[i].push_back(j);
			}
		}
	}

	finished.resize(N);
	parents.resize(N);

	for (int i = 0; i < N; i++) {
		if (finished[i]) continue;

		visited.clear();
		visited.resize(N);
		DFS(i);
	}

	cout << sum;

	return 0;
}