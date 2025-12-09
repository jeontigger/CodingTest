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
#include <iomanip>
#include <cassert>
#include <cstring>
#include <list>

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
#define FOR(idx, limit) for(int idx = 0; idx < limit; idx++)
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

int N, M;
vector<vector<int>> edges;

bool Inputs() {
	cin >> N >> M;
	edges.resize(N + 1);
	FOR(i, M) {
		int n1, n2;
		cin >> n1 >> n2;
		edges[n1].push_back(n2);
		edges[n2].push_back(n1);
	}

	//for (int i = 0; i < edges.size(); i++) {
	//	sort(edges[i].begin(), edges[i].end());
	//	edges[i].erase(unique(edges[i].begin(), edges[i].end()), edges[i].end());
	//}
	return true;
}

struct Data {
	int node;
	int dist;
};

int KB(int n) {
	vector<int> distance(N + 1, INF);
	distance[n] = 0;

	queue<Data> q;
	q.push({ n, 0 });

	while (!q.empty()) {
		Data cur = q.front();
		q.pop();

		for (int i = 0; i < edges[cur.node].size(); i++) {
			int next = edges[cur.node][i];
			if (distance[next] > cur.dist + 1) {
				distance[next] = cur.dist + 1;
				q.push({ next, cur.dist + 1 });
			}
		}
	}

	int ret = 0;
	for (int i = 1; i <= N; i++) {
		ret += distance[i];
	}

	return ret;
}

void Solution() {

	int minValue = INF;
	int res = 0;
	for (int i = 1; i <= N; i++) {
		int ret = KB(i);
		if (ret < minValue) {
			minValue = ret;
			res = i;
		}
	}
	cout << res << '\n';
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 1;
	//cin >> T;
	while (T--) {
		if (!Inputs()) break;
		Solution();
	}

	return 0;
}