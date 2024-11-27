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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> portal(111);
	for (int i = 0; i < N + M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		portal[v1] = v2;
	}

	queue<int> q;
	q.push(1);

	vector<bool>visited(111);
	visited[1] = true;

	int cnt = -1;
	while (!q.empty()) {
		cnt++;

		int size = q.size();
		while (size--) {
			int curNum = q.front();
			q.pop();

			if (curNum == 100) {
				cout << cnt;
				return 0;
			}

			for (int i = 1; i <= 6; i++) {
				int next = curNum + i;
				if (portal[next] != 0) next = portal[next];
				if (visited[next]) continue;
				visited[next] = true;
				q.push(next);
			}
		}
	}


	return 0;
}