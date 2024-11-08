
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
	int pos;
	int cnt;
};

struct cmp {
	bool operator()(const Data& d1, const Data& d2) {
		return d1.cnt > d2.cnt;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int MAX = 1000000;
	vector<int> visited(MAX, INF);
	priority_queue<Data, vector<Data>, cmp> pq;

	int N, K;
	cin >> N >> K;
	pq.push({ N, 0 });
	visited[N] = 0;

	while (!pq.empty()) {
		int n = pq.size();
		int curPos = pq.top().pos;
		int curCnt = pq.top().cnt;
		pq.pop();

		if (curPos == K) {
			cout << curCnt;
			return 0;
		}

		//cout << curPos << " ";

		int nextPos;
		nextPos = curPos + 1;

		if (nextPos < MAX && visited[nextPos] > curCnt + 1) {
			visited[nextPos] = curCnt + 1;
			pq.push({ nextPos , curCnt + 1 });
		}

		nextPos = curPos - 1;
		if (nextPos >= 0 && visited[nextPos] > curCnt + 1) {
			visited[nextPos] = curCnt + 1;
			pq.push({ nextPos , curCnt + 1 });
		}


		nextPos = curPos * 2;
		if (nextPos < MAX && visited[nextPos] > curCnt) {
			visited[nextPos] = curCnt;
			pq.push({ nextPos , curCnt });
		}
	}


	return 0;
}