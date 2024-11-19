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
	cout << endl;
}

template<typename T>
void PrintVec(const vector<vector<T>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> edges(N + 1);
	vector<int> visited(N + 1);
	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}

	queue<int> q;

	q.push(1);
	visited[1] = true;

	int cnt = 0;
	while (!q.empty()) {
		int curNode = q.front();
		q.pop();

		for (int i = 0; i < edges[curNode].size(); i++) {
			int nextNode = edges[curNode][i];
			if (visited[nextNode]) continue;
			visited[nextNode] = true;
			q.push(nextNode);
			cnt++;
		}

	}

	cout << cnt;


	return 0;
}