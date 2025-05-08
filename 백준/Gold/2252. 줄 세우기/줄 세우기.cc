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

struct Data {
	int in;
	vector<int> next;
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<Data> vec(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		vec[b].in++;
		vec[a].next.push_back(b);
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (vec[i].in == 0) {
			q.push(i);
		}
	}

	vector<int> visited(N + 1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (visited[cur]) continue;
		cout << cur << ' ';
		visited[cur] = true;

		for (int i = 0; i < vec[cur].next.size(); i++) {
			int next = vec[cur].next[i];
			if (visited[next]) continue;
			vec[next].in--;
			if (vec[next].in == 0) {
				q.push(next);
			}
		}
	}


	return 0;
}
