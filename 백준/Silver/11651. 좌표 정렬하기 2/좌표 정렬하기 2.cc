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

struct Pos {
	int x;
	int y;
};

bool cmp(const Pos& p1, const Pos& p2) {
	return p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<Pos> poss(N);
	for (int i = 0; i < N; i++) {
		cin >> poss[i].x >> poss[i].y;
	}

	sort(poss.begin(), poss.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << poss[i].x << " " << poss[i].y << '\n';
	}


	return 0;
}
