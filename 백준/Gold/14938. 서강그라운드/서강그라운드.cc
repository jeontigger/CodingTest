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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, R;
	cin >> N >> M >> R;

	vector<int> nums(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	vector<vector<int>> maps(N, vector<int>(N, INF));
	for (int i = 0; i < R; i++) {
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		v1--, v2--;
		maps[v1][v2] = c;
		maps[v2][v1] = c;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				maps[i][j] = min(maps[i][j], maps[i][k] + maps[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		maps[i][i] = 0;
	}

	int maxValue = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (maps[i][j] <= M)
				sum += nums[j];
		}
		maxValue = max(maxValue, sum);
	}

	cout << maxValue;



	return 0;
}
