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
	vector<bool>visited(N + 1);
	vector<vector<int>> edges(N + 1);

	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}

	int cnt = 0;
	for (int i = 1; i < N + 1; i++) {
		if (visited[i]) continue;

		queue<int> q;
		cnt++;
		q.push(i);
		visited[i] = true;
		//cout << i << endl;
		while (!q.empty()) {
			int curNode = q.front();
			//cout << curNode << " ";
			q.pop();

			//if (visited[curNode]) continue;

			for (int j = 0; j < edges[curNode].size(); j++) {
				int next = edges[curNode][j];

				//cout << curNode << " " << next << endl;
				if (visited[next]) continue;
				visited[next] = true;
				q.push(next);
			}
		}
	}

	cout << cnt;

	return 0;
}