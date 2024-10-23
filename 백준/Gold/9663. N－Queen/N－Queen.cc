#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

#define INF 1e9


void PrintVec(const vector<int>& v) {
	for (int i : v) {
		printf("%d ", i);
	}
	printf("\n");
}

void PrintVec(const vector<vector<int>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

bool CrossQueen(vector<int>& queens, int idx, int depth) {

	// 좌상단 && 좌하단
	for (int i = 1; i <= idx; i++) {
		if (queens[idx - i] == depth - i || queens[idx - i] == depth + i) {
			return true;
		}
	}

	// 우상단 && 우하단 
	for (int i = 1; i < queens.size() - idx; i++) {
		if (queens[idx + i] == depth - i || queens[idx + i] == depth + i) {
			return true;
		}
	}

	return false;
}

bool VerticalQueen(vector<int>& queens, int idx, int depth) { return true; }

int g_res = 0;
void NQueen(int N, vector<int>& queens, int depth) {

	if (depth == N) {
		g_res++;

		//PrintVec(queens);
		return;
	}

	for (int i = 0; i < N; i++) {
		// 세로축 제외
		if (queens[i] != -100) continue;

		// 가로축 제외
		if (queens[i] == depth) continue;

		// 대각선 제외
		if (CrossQueen(queens, i, depth)) continue;

		queens[i] = depth;
		NQueen(N, queens, depth + 1);
		queens[i] = -100;
	}


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> queens(N, -100);
	NQueen(N, queens, 0);

	cout << g_res << endl;
	return 0;
}