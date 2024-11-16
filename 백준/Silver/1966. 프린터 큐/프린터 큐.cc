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

struct Data {
	int idx;
	int val;
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;

		queue<Data> q;
		priority_queue<int> pq;
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			q.push({ i, n });
			pq.push(n);
		}

		int cnt = 0;
		while (!q.empty()) {
			Data curData = q.front();
			q.pop();

			if (curData.val == pq.top()) {
				pq.pop();
				cnt++;

				if (curData.idx == M) {
					cout << cnt << ' ';
					break;
				}
				continue;
			}

			q.push(curData);
		}


	}

	return 0;
}