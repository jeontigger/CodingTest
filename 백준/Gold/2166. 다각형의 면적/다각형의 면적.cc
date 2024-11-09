#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <set>

using namespace std;

#define INF 1e12

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
	long long x;
	long long y;
};

double Cross(Pos p1, Pos p2, Pos p3) {
	return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	cin >> N;
	vector<Pos>poses(N);
	for (int i = 0; i < N; i++) {
		cin >> poses[i].x >> poses[i].y;
	}

	Pos start = poses[0];

	double res = 0;
	for (int i = 2; i < N; i++) {
		res += Cross(start, poses[i - 1], poses[i]);
	}
	printf("%.1f", abs(round(10 * res / 2) / 10));

	return 0;
}