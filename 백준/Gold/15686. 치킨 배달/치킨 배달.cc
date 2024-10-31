

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
	int row;
	int col;
};

void ChickenLength(const vector<Pos>& houses, const vector<Pos>& chickens, int depth, int target, vector<bool>& visited, int& value) {
	if (depth == target) {

		int sum = 0;
		for (int i = 0; i < houses.size(); i++) {
			int hrow = houses[i].row;
			int hcol = houses[i].col;

			int minValue = INF;
			for (int j = 0; j < chickens.size(); j++) {
				if (!visited[j]) continue;

				int crow = chickens[j].row;
				int ccol = chickens[j].col;
				int val = abs(hrow - crow) + abs(hcol - ccol);

				minValue = min(minValue, val);
			}
			sum += minValue;
			if (sum > value) return;
		}
		value = sum;

		return;
	}

	for (int i = 0; i < chickens.size(); i++) {
		if (visited[i]) continue;

		visited[i] = true;
		ChickenLength(houses, chickens, depth + 1, target, visited, value);
		visited[i] = false;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<Pos> houses;
	vector<Pos> chickens;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 1) {
				houses.push_back({ i, j });
			}
			else if (num == 2) {
				chickens.push_back({ i, j });
			}
		}
	}

	int depth = 0;
	vector<bool> visited(chickens.size());
	int value = INF;
	//ChickenLength(houses, chickens, depth, M, visited, value);

	for (int i = 0; i < M; i++) {
		visited[i] = true;
	}
	reverse(visited.begin(), visited.end());

	int minSum = INF;
	do {

		int sum = 0;
		for (int i = 0; i < houses.size(); i++) {
			int hrow = houses[i].row;
			int hcol = houses[i].col;

			int minValue = INF;
			for (int j = 0; j < chickens.size(); j++) {
				if (!visited[j]) continue;
				int crow = chickens[j].row;
				int ccol = chickens[j].col;

				int len = abs(hrow - crow) + abs(hcol - ccol);
				minValue = min(minValue, len);
			}
			sum += minValue;
		}

		minSum = min(minSum, sum);
	} while (next_permutation(visited.begin(), visited.end()));

	cout << minSum << endl;
	return 0;
}