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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, B;
	cin >> N >> M >> B;

	vector<vector<int>> maps(N, vector<int>(M));

	int left = INF, right = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];

			left = min(left, maps[i][j]);
			right = max(right, maps[i][j]);
		}
	}

	int minValue = INF;

	int lastHeight = -1;
	for (int height = left; height <= right; height++) {
		int block = B;
		int sum = 0;
		bool issuccess = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (maps[i][j] < height) {
					block -= height - maps[i][j];
					sum += (height - maps[i][j]) * 1;
				}
				else if (maps[i][j] > height) {
					block += maps[i][j] - height;
					sum += (maps[i][j] - height) * 2;
				}
				else {
				}
			}
		}

		if (block >= 0) {
			if (sum <= minValue) {
				minValue = sum;
				lastHeight = height;
			}
		}
	}

	cout << minValue << " " << lastHeight;



	return 0;
}