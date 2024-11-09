#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <set>

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

struct Node {
	int in;
	int idx;
	int delay;
};

struct cmp {
	bool operator()(const Node& n1, const Node& n2) {
		return n1.delay > n2.delay;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int N, K;
	while (T--) {
		cin >> N >> K;

		vector<Node> buildings(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> buildings[i].delay;
			buildings[i].idx = i;
		}

		vector<vector<int>>edges(N + 1);

		int v1, v2;
		for (int i = 0; i < K; i++) {
			cin >> v1 >> v2;
			edges[v1].push_back(v2);
			buildings[v2].in++;
		}

		int target;
		cin >> target;

		priority_queue<Node, vector<Node>, cmp> pq;

		for (int i = 1; i < N + 1; i++) {
			if (buildings[i].in == 0) {
				pq.push(buildings[i]);
			}
		}

		vector<bool>visited(N + 1);

		while (!pq.empty()) {
			Node node = pq.top();
			pq.pop();

			if (node.idx == target) {
				cout << node.delay << endl;
				break;
			}

			if (visited[node.idx])continue;
			visited[node.idx] = true;

			for (int i = 0; i < edges[node.idx].size(); i++) {
				int nextNode = edges[node.idx][i];
				if (visited[nextNode]) continue;

				buildings[nextNode].in--;
				if (buildings[nextNode].in == 0) {
					pq.push({ 0, nextNode, node.delay + buildings[nextNode].delay });
				}
			}
		}

	}

	return 0;
}