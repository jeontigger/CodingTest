
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

struct Pos {
	int x;
	int y;
};

bool cmp(const Pos& p1, const Pos& p2) {
	return p1.x == p2.x ? p1.y > p2.y : p1.x < p2.x;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;

	vector<Pos> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].x >> v[i].y;
	}
	sort(v.begin(), v.end(), cmp);

	int sum = 0;
	int left = -INF, right = -INF;
	for (int i = 0; i < N; i++) {
		int l = v[i].x;
		int r = v[i].y;
		if (l > right) {
			sum += right - left;
			right = r;
			left = l;
		}
		else if (l <= right && right < r) {
			right = r;
		}
	}
	sum += right - left;

	cout << sum;


	return 0;
}