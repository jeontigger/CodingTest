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

int A, B;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;

	queue<long long> q;
	q.push(A);

	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		int size = q.size();
		while (size--) {
			long long curNum = q.front();
			q.pop();

			if (curNum > B)continue;

			//cout << curNum << ' ';

			if (curNum == B) {
				cout << cnt;
				return 0;
			}

			long long next;
			next = curNum * 2;
			q.push(next);

			next = curNum * 10 + 1;
			q.push(next);
		}
	}

	cout << -1;

	return 0;
}