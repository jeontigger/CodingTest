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

struct Matrix {
	int r;
	int c;
};

vector<vector<long long>> dp;

long long DC(const vector<Matrix>& matrixs, int start, int end) {

	if (dp[start][end] != INF) {
		return dp[start][end];
	}

	for (int i = start; i < end; i++) {

		long long left = DC(matrixs, start, i);
		long long right = DC(matrixs, i + 1, end);

		long long sum = left + right + matrixs[start].r * matrixs[i + 1].r * matrixs[end].c;
		dp[start][end] = min(dp[start][end], sum);
	}

	return dp[start][end];
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<Matrix> matrixs(N);
	dp.resize(N, vector<long long>(N, INF));
	for (int i = 0; i < N; i++) {
		dp[i][i] = 0;
	}

	for (int i = 0; i < N; i++) {
		cin >> matrixs[i].r >> matrixs[i].c;
	}

	DC(matrixs, 0, N - 1);

	cout << dp[0][N - 1];
	return 0;
}