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

struct Edge {
	int node;
	int cost;
};

vector<vector<Edge>> edges;
int maxDiameter = 0;

int GetDiameter(int curNode) {

	priority_queue<int> pq;

	for (int i = 0; i < edges[curNode].size(); i++) {
		int next = edges[curNode][i].node;
		int cost = edges[curNode][i].cost + GetDiameter(next);
		pq.push(cost);
	}

	int cnt = 2;
	int curValue = 0;
	int maxValue = 0;
	if (!pq.empty())
		maxValue = pq.top();
	while (!pq.empty() && cnt--) {
		curValue += pq.top();
		pq.pop();
	}

	maxDiameter = max(curValue, maxDiameter);

	return  maxValue;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	edges.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		edges[v1].push_back({ v2, c });
	}

	GetDiameter(1);

	cout << maxDiameter;

	return 0;
}
