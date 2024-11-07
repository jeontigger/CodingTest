
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

vector<int> parents;

int Find(int x) {
	if (parents[x] == x)
		return x;
	return parents[x] = Find(parents[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	parents[a] = b;
}

struct Edge {
	int w;
	int v1;
	int v2;
};

int Kruskal(const vector<Edge>& edges, int N) {
	int res = 0;

	int cnt = 0;
	for (int i = 0; i < edges.size(); i++) {
		if (cnt == N - 1) break;

		int v1 = edges[i].v1;
		int v2 = edges[i].v2;

		if (Find(v1) == Find(v2)) continue;

		cnt++;
		Union(v1, v2);

		res += edges[i].w;
		//cout << edges[i].w << " ";
	}

	return res;
}

bool cmp(const Edge& e1, const Edge& e2) {
	return e1.w < e2.w;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	parents.resize(N + 1);
	for (int i = 0; i < N + 1; i++) {
		parents[i] = i;
	}

	vector <Edge>edges(M);

	int w, v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> edges[i].v1 >> edges[i].v2 >> edges[i].w;
	}

	sort(edges.begin(), edges.end(), cmp);

	cout << Kruskal(edges, N);

	return 0;
}