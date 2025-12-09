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

int N, K;
vector<int> visited;
bool Inputs() {
	cin >> N >> K;
	return true;
}

struct Data {
	int n;
	int t;
};

bool IsValid(int n, int t) {
	if (n < 0 || n > 100000) return false;

	return visited[n] > t;
}
struct cmp {
	bool operator()(const Data& d1, const Data& d2) {
		return d1.t > d2.t;
	}
};
void Teleport(priority_queue<Data, vector<Data>, cmp>& pq, int n, int t) {

	while (true) {
		n *= 2;
		if (!IsValid(n, t)) break;

		pq.push({ n, t });
		visited[n] = true;
	}
}

void Solution() {
	priority_queue<Data, vector<Data>, cmp> pq;
	pq.push({ N, 0 });
	visited.resize(1000001, INF);
	visited[N] = 0;
	//Teleport(pq, N, 0);

	while (!pq.empty()) {
		Data cur = pq.top();
		pq.pop();

		//cout << cur.n << ' ' << cur.t << '\n';

		if (cur.n == K) {
			cout << cur.t << '\n';
			return;
		}

		Data cand[3] = { {cur.n - 1, cur.t + 1}, {cur.n + 1, cur.t + 1}, {cur.n * 2 , cur.t} };
		for (int i = 0; i < 3; i++) {
			Data next = cand[i];
			if (IsValid(next.n, next.t)) {
				visited[next.n] = next.t;
				pq.push(next);
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