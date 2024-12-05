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

vector<vector<char>> maps;

void PrintTri(int left, int top) {
	maps[top][left + 2] = '*';
	maps[top + 1][left + 1] = '*', maps[top + 1][left + 3] = '*';
	for (int i = 0; i < 5; i++) {
		maps[top + 2][left + i] = '*';
	}
}

void PrintStar(int left, int top, int N) {
	if (N == 3) {
		PrintTri(left, top);
		return;
	}

	// 상
	PrintStar(left + N / 2, top, N / 2);

	// 좌
	PrintStar(left, top + N / 2, N / 2);

	// 우
	PrintStar(left + N, top + N / 2, N / 2);

}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	maps.resize(N, vector<char>(N * 2 - 1, ' '));

	PrintStar(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2 - 1; j++) {
			cout << maps[i][j];
		}
		cout << '\n';
	}

	return 0;
}
