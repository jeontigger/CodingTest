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

int M;
pair<int, int> comm[51];

void Inputs() {
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> comm[i].first >> comm[i].second;
	}
}

void Solution() {
	vector<int> balls(4);
	balls[1] = 1;

	for (int i = 0; i < M; i++) {
		swap(balls[comm[i].first], balls[comm[i].second]);
	}

	int idx = -1;
	for (int i = 1; i < balls.size(); i++) {
		if (balls[i] == 1) {
			idx = i;
		}
	}
	cout << idx;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	//cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}