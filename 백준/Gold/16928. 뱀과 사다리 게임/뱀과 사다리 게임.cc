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

int N, M;
vector<int> ladder;
vector<int> snake;
int SnakeLadder() {

	queue<int> q;
	q.push(1);

	vector<bool> visited(101);

	int cnt = 0;
	while (!q.empty()) {
		cnt++;

		int size = q.size();
		while (size--) {
			int curNum = q.front();
			q.pop();
			if (visited[curNum]) continue;
			visited[curNum] = true;

			for (int i = 1; i <= 6; i++) {
				int nextNum = curNum + i;

				if (nextNum > 100)continue;

				if (nextNum == 100) {
					return cnt;
				}

				if (ladder[nextNum] != 0) {
					q.push(ladder[nextNum]);
				}
				else if (snake[nextNum] != 0) {
					q.push(snake[nextNum]);
				}
				else {
					q.push(nextNum);
				}
			}
		}
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	ladder.resize(101);
	for (int i = 0; i < N; i++) {
		int f, t;
		cin >> f >> t;
		ladder[f] = t;
	}

	snake.resize(101);
	for (int i = 0; i < M; i++) {
		int f, t;
		cin >> f >> t;
		snake[f] = t;
	}

	cout << SnakeLadder();

	return 0;
}