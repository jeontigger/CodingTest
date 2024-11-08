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

struct Pos {
	int x;
	int y;
	int z;
};

int Distance(Pos p1, Pos p2) {
	int res = min(min(abs(p1.x - p2.x), abs(p1.y - p2.y)), abs(p1.z - p2.z));
	return res;
}

//struct Edge {
//	int distance;
//	int to;
//};
//
//struct cmp {
//	bool operator()(const Edge& e1, const Edge& e2) {
//		return e1.distance > e2.distance;
//	}
//};
//
//long long Prim(const vector<Pos>& planets) {
//	long long res = 0;
//
//	priority_queue<Edge, vector<Edge>, cmp> pq;
//
//	pq.push({ 0, 0 });
//
//	while (!pq.empty()) {
//		Edge edge = pq.top();
//		pq.pop();
//
//		int curNode = edge.to;
//		int curDist = edge.distance;
//
//		if (visited[curNode]) continue;
//		visited[curNode] = true;
//		res += curDist;
//
//		for (int i = 0; i < planets.size(); i++) {
//			int nextNode = i;
//			if (visited[nextNode]) continue;
//			int dist = Distance(planets[curNode], planets[nextNode]);
//			pq.push({ dist, i });
//		}
//	}
//
//	return res;
//}


struct Edge {
	int dist;
	int v1;
	int v2;
};

bool cmp(const Edge& e1, const Edge& e2) {
	return e1.dist < e2.dist;
}

struct Data {
	int val;
	int idx;
};

bool datacmp(const Data& d1, const Data& d2) {
	return d1.val < d2.val;
}

void MakeEdges(const vector<Pos>& planets, vector<Edge>& edges) {
	int n = planets.size();
	vector<Data> vecx(n);
	vector<Data> vecy(n);
	vector<Data> vecz(n);
	for (int i = 0; i < n; i++) {
		vecx[i].val = planets[i].x;
		vecy[i].val = planets[i].y;
		vecz[i].val = planets[i].z;
		vecx[i].idx = i;
		vecy[i].idx = i;
		vecz[i].idx = i;
	}

	sort(vecx.begin(), vecx.end(), datacmp);
	sort(vecy.begin(), vecy.end(), datacmp);
	sort(vecz.begin(), vecz.end(), datacmp);

	for (int i = 1; i < n; i++) {
		edges.push_back({ vecx[i].val - vecx[i - 1].val , vecx[i].idx, vecx[i - 1].idx });
		edges.push_back({ vecy[i].val - vecy[i - 1].val , vecy[i].idx, vecy[i - 1].idx });
		edges.push_back({ vecz[i].val - vecz[i - 1].val , vecz[i].idx, vecz[i - 1].idx });
	}

	sort(edges.begin(), edges.end(), cmp);
}

vector<int> parents;

int Find(int x) {
	if (x == parents[x])
		return x;
	else
		return parents[x] = Find(parents[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	parents[a] = b;
}

long long Kruskal(const vector<Pos>& planets) {
	vector<Edge> edges;
	MakeEdges(planets, edges);

	long long res = 0;
	for (int i = 0; i < edges.size(); i++) {
		Edge edge = edges[i];

		if (Find(edge.v1) == Find(edge.v2)) continue;

		Union(edge.v1, edge.v2);
		//cout << edge.v1 << " " << edge.v2 << " " << edge.dist << endl;
		res += edge.dist;
	}

	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	parents.resize(N);
	for (int i = 0; i < N; i++) {
		parents[i] = i;
	}

	vector<Pos> planets(N);
	for (int i = 0; i < N; i++) {
		cin >> planets[i].x >> planets[i].y >> planets[i].z;
	}

	//cout << Prim(planets);
	cout << Kruskal(planets);


	return 0;
}