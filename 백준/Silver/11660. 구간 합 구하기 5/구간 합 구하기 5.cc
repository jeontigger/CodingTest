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

vector<vector<int>> sums;

long long GetSum(int row, int y1, int y2) {
	return (long long)sums[row][y2] - sums[row][y1 - 1];
}

long long GetSum(int x1, int y1, int x2, int y2) {

	long long sum = 0;

	for (int i = x1; i <= x2; i++) {
		sum += GetSum(i, y1, y2);
	}

	return sum;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	sums.resize(N, vector<int>(N + 1));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sums[i][j + 1];
			sums[i][j + 1] += sums[i][j];
		}
	}

	//PrintVec(sums);

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, x2--;

		cout << GetSum(x1, y1, x2, y2) << ' ';
	}

	return 0;
}