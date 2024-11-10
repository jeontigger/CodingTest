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

vector<vector<int>> edges;
vector<int> indegree;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	edges.resize(N + 1);
	indegree.resize(N + 1);

	int num, prev;
	int cnt;
	for (int i = 0; i < M; i++) {
		cin >> cnt;
		cin >> num;
		prev = num;
		for (int j = 1; j < cnt; j++) {
			cin >> num;
			indegree[num]++;
			edges[prev].push_back(num);
			prev = num;
		}
	}

	vector<int> visited(N + 1);

	queue<int> q;
	for (int i = 1; i < N + 1; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> seq;
	while (!q.empty()) {
		int curNode = q.front();
		q.pop();

		if (visited[curNode]) continue;
		visited[curNode] = true;
		seq.push_back(curNode);

		for (int i = 0; i < edges[curNode].size(); i++) {
			int nextNode = edges[curNode][i];
			if (visited[nextNode]) continue;
			indegree[nextNode]--;
			if (indegree[nextNode] == 0) {
				q.push(nextNode);
			}
		}
	}

	if (seq.size() == N) {
		PrintVec(seq);
	}
	else {
		cout << 0 << endl;
	}


	return 0;
}