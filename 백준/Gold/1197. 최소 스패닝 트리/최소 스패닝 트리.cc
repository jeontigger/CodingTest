#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

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

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

struct Data {
	int to;
	int weight;
};

struct cmp {
	bool operator () (const Data& d1, const Data& d2) {
		return d1.weight > d2.weight;
	}
};

int MST(vector<vector<Data>>& edges) {

	int n = edges.size();
	vector<int> visited(n);

	priority_queue<Data, vector<Data>, cmp> pq;
	pq.push({ 1, 0 });
	//visited[0] = true;
	long long sum = 0;
	while (!pq.empty()) {

		int curNode = pq.top().to;
		int weight = pq.top().weight;
		pq.pop();

		if (visited[curNode]) continue;
		visited[curNode] = true;

		sum += weight;

		for (int i = 0; i < edges[curNode].size(); i++) {
			int nextNode = edges[curNode][i].to;
			int nextWeight = edges[curNode][i].weight;

			if (visited[nextNode]) continue;
			pq.push(edges[curNode][i]);
		}
	}

	return sum;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;
	V++;

	vector<vector<Data>>edges(V);
	for (int i = 0; i < E; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		//v1--;
		//v2--;

		edges[v1].push_back({ v2, w });
		edges[v2].push_back({ v1, w });
	}

	cout << MST(edges);


	return 0;
}