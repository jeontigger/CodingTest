#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

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

struct Edge {
	int from;
	int to;
	int cost;
};

bool Bellman(vector<Edge>& edges, int start, int N, vector<long long>& dist) {

	dist[start] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < edges.size(); j++) {
			int from = edges[j].from;
			int to = edges[j].to;
			int cost = edges[j].cost;

			//cout << from << " " << to << " " << cost << " " << dist[to] << " " << dist[from] << endl;
			if (dist[from] != INF && dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;

				if (i == N - 1) return false;
			}
		}
	}

	//PrintVec(dist);
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc, N, M, W;
	cin >> tc;
	while (tc) {
		tc--;

		cin >> N >> M >> W;
		vector<Edge>edges;

		int f, t, c;
		for (int i = 0; i < M + W; i++) {
			cin >> f >> t >> c;
			if (i < M)
			{
				edges.push_back({ f, t, c });
				edges.push_back({ t, f, c });
			}
			else
				edges.push_back({ t, f, -c });
		}

		bool yes = false;
		vector<long long> dist(N + 1, INF);
		for (int i = 1; i <= N; i++) {
			if (dist[i] != INF) continue;
			if (!Bellman(edges, i, N, dist)) {
				yes = true;
				break;
			}
		}

		yes ? cout << "YES" : cout << "NO";
		cout << '\n';
	}

	return 0;
}