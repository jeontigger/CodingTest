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

struct Edge {
	int delay;
	int in;
	vector<int> out;
};

struct Data {
	int idx;
	int delay;
};

struct cmp {
	bool operator()(const Data& d1, const Data& d2) {
		return d1.delay > d2.delay;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<Edge> edges(N + 1);

	for (int i = 1; i < N + 1; i++) {
		int t, n;
		cin >> t;

		edges[i].delay = t;
		while (true) {
			cin >> n;
			if (n == -1) break;
			edges[n].out.push_back(i);
			edges[i].in++;
		}
	}

	priority_queue<Data, vector<Data>, cmp>pq;
	for (int i = 1; i < N + 1; i++) {
		if (edges[i].in == 0) {
			pq.push({ i, edges[i].delay });
		}
	}

	vector<int> delays(N + 1);

	while (!pq.empty()) {
		Data data = pq.top();
		pq.pop();

		delays[data.idx] = data.delay;

		for (int i = 0; i < edges[data.idx].out.size(); i++) {
			int nextNode = edges[data.idx].out[i];
			edges[nextNode].in--;
			if (edges[nextNode].in == 0) {
				int nextDelay = edges[nextNode].delay;
				pq.push({ nextNode, data.delay + nextDelay });
			}
		}
	}

	for (int i = 1; i < N + 1; i++) {
		cout << delays[i] << " ";
	}


	return 0;
}