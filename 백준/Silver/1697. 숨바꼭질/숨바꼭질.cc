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
	cout << endl;
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

	int N, K;
	cin >> N >> K;

	queue<int> q;

	vector<bool> visited(100001);
	visited[N] = true;
	q.push(N);

	int cnt = -1;
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		while (size--) {

			int curNum = q.front();
			q.pop();

			if (curNum > 100000) continue;

			if (curNum == K) {
				cout << cnt;
				return 0;
			}

			int next;
			next = curNum + 1;
			if (0 <= next && next < 100001 && !visited[next])
			{
				visited[next] = true;
				q.push(next);
			}

			next = curNum - 1;
			if (0 <= next && next < 100001 && !visited[next])
			{
				visited[next] = true;
				q.push(next);
			}

			next = curNum * 2;
			if (0 <= next && next < 100001 && !visited[next])
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}

	return 0;
}