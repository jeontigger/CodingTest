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
	int delay;
	int in;
};

struct Build {
	int time;
	int node;
};

struct cmp {
	bool operator()(const Build& b1, const Build& b2) {
		return b1.time > b2.time;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	int N, K;
	while (T) {
		T--;
		cin >> N >> K;

		vector<vector<int>> edges(N + 1);
		vector<Data> nodes(N + 1);
		for (int i = 0; i < N; i++) {
			cin >> nodes[i + 1].delay;
		}

		int f, t;
		for (int i = 0; i < K; i++) {
			cin >> f >> t;
			nodes[t].in++;
			edges[f].push_back(t);
		}

		int W;
		cin >> W;


		priority_queue < Build, vector<Build>, cmp> pq;
		for (int i = 1; i <= N; i++) {
			if (nodes[i].in == 0) {
				pq.push({ nodes[i].delay, i });
			}
		}

		while (!pq.empty()) {
			Build build = pq.top();
			pq.pop();

			if (build.node == W) {
				cout << build.time << endl;
				break;
			}

			for (int i = 0; i < edges[build.node].size(); i++) {
				int nextNode = edges[build.node][i];
				nodes[nextNode].in--;
				if (nodes[nextNode].in == 0) {
					pq.push({ build.time + nodes[nextNode].delay, nextNode });
				}
			}
		}
	}



	return 0;
}