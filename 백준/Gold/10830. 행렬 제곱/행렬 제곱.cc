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

long long N, B;
vector<vector<int>> matrix;

vector<vector<int>> matPow(long long B) {
	if (B == 1) {
		return matrix;
	}

	vector<vector<int>> res(N, vector<int>(N));
	if (B % 2 == 0) {
		auto ret = matPow(B / 2);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					res[i][j] = (res[i][j] + ret[i][k] * ret[k][j]) % 1000;
				}
			}
		}
		// ret* ret;
	}
	else {
		auto ret = matPow(B - 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					res[i][j] = (res[i][j] + ret[i][k] * matrix[k][j]) % 1000;
				}
			}
		}
		// ret * mat;
	}

	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> B;
	matrix.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}

	auto ret = matPow(B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ret[i][j] % 1000 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
