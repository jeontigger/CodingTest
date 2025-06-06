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

	priority_queue<int, vector<int>, greater<int>> pq;

	int N;
	cin >> N;
	while (N--) {
		int n;
		cin >> n;

		if (n == 0) {
			if (pq.empty()) {
				cout << 0 << ' ';
			}
			else {
				cout << pq.top() << ' ';
				pq.pop();
			}
		}
		else {
			pq.push(n);
		}
	}



	return 0;
}