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
#include <iomanip>
#include <cassert>
#include <cstring>
#include <list>

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
#define FOR(idx, limit) for(int idx = 0; idx < limit; idx++)
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

// 벽을 최소 몇개 부숴야 하는지?
// 그럼 벽을 부순 개수를 갖는 pq를 사용해야할듯?

int N, M;
vector<vector<int>> maps;

bool Inputs() {
	cin >> M >> N;

	maps.resize(N, vector<int>(M));
	FOR(i, N)
		FOR(j, M)
	{
		char ch;
		cin >> ch;
		maps[i][j] = ch - '0';
	}

	return true;
}

struct Data {
	int r;
	int c;
	int b;
	int step;
};

struct cmp {
	bool operator()(const Data& d1, const Data& d2) {
		if (d1.b != d2.b) {
			return d1.b > d2.b;
		}
		else {
			return d1.step > d2.step;
		}
	}
};

bool IsValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M)return false;
	return true;
}

void Solution() {

	// [r][c] = b
	vector<vector<int>> visited(N, vector<int>(M, INF));
	priority_queue<Data, vector<Data>, cmp> pq;
	pq.push({ 0, 0 });
	visited[0][0] = 0;

	while (!pq.empty()) {
		Data cur = pq.top();
		pq.pop();

		if (cur.r == N - 1 && cur.c == M - 1) {
			cout << cur.b << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];

			// 바운더리 검사
			if (IsValid(nr, nc)) {
				// 벽이라면
				int nb = cur.b;
				if (maps[nr][nc] == 1) {
					nb++;
				}

				if (visited[nr][nc] > nb) {
					visited[nr][nc] = nb;
					pq.push({ nr, nc, nb, cur.step + 1 });
				}
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 1;
	//cin >> T;
	while (T--) {
		if (!Inputs()) break;
		Solution();
	}

	return 0;
}