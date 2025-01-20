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

vector<string>  maps;
int DiffCnt(int row, int col, bool type) {
	// true == W, false == B

	int res = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char ch = maps[row + i][col + j];
			if (type) {
				if ((i + j) % 2 == 0) {
					if (ch == 'W')
						res++;
				}
				else {
					if (ch == 'B')
						res++;
				}
			}
			else {
				if ((i + j) % 2 == 0) {
					if (ch == 'B')
						res++;
				}
				else {
					if (ch == 'W')
						res++;
				}
			}

		}
	}
	return 64 - res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	maps.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> maps[i];
	}

	int res = INF;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			res = min(res, DiffCnt(i, j, false));
			res = min(res, DiffCnt(i, j, true));
		}
	}

	cout << res;

	return 0;
}
