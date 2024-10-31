
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

int DFS(const vector<int>& students, vector<bool>& visited, vector<int>& path, int curNode) {


	int nextNode = students[curNode];

	int res = 0;
	if (visited[nextNode]) {
		auto iter = find(path.begin(), path.end(), nextNode);
		if (iter == path.end()) {
			// 이미 팀이 형성된 경우

			return 0;
		}
		else {
			// 사이클 형성 개수
			return path.size() - (iter - path.begin());
		}
	}
	else {
		// 아직 사이클 미탐색
		visited[nextNode] = true;
		path.push_back(nextNode);
		res = DFS(students, visited, path, nextNode);
	}

	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	cin >> T;

	while (T) {
		T--;

		cin >> N;
		vector<int> students(N + 1);

		for (int i = 1; i < N + 1; i++) {
			cin >> students[i];
		}
		vector<bool> visited(N + 1);
		visited[0] = true;

		int sum = 0;
		for (int i = 1; i < N + 1; i++) {
			if (visited[i]) continue;

			vector<int> path;
			visited[i] = true;
			path.push_back(i);
			sum += DFS(students, visited, path, i);
		}
		cout << N - sum << endl;
	}

	return 0;
}