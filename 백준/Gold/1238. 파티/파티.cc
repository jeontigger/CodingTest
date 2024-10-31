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

struct Data {
	int to;
	int t;
};

struct cmp {
	bool operator()(const Data& d1, const Data& d2) {
		return d1.t == d2.t ? d1.to > d2.to : d1.t > d2.t;
	}
};

int Dijkstra(vector<vector<Data>>& edges, int start, int end) {

	priority_queue<Data, vector<Data>, cmp>pq;

	pq.push({ start, 0 });

	vector<bool> visited(edges.size());

	int timeSum = 0;
	while (!pq.empty()) {
		int curNode = pq.top().to;
		int curTime = pq.top().t;
		pq.pop();


		if (visited[curNode]) continue;
		visited[curNode] = true;
		timeSum += curTime;
		//cout << curNode << " " << curTime << endl;

		if (curNode == end) {
			return curTime;
		}


		for (int i = 0; i < edges[curNode].size(); i++) {
			int nextNode = edges[curNode][i].to;
			int nextTime = edges[curNode][i].t;

			if (visited[nextNode]) continue;
			pq.push({ nextNode, nextTime + curTime });
		}
	}

	return timeSum;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, X;
	cin >> N >> M >> X;

	vector<vector<Data>> edges(N + 1);
	int a, b, t;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> t;
		edges[a].push_back({ b, t });
	}

	int maxValue = 0;
	for (int i = 1; i < N + 1; i++) {
		int in = Dijkstra(edges, i, X);
		int out = Dijkstra(edges, X, i);
		maxValue = max(maxValue, in + out);
	}

	cout << maxValue;

	return 0;
}