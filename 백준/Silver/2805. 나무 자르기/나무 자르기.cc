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
int N, M;

bool IsValid(int testNum, vector<int>& trees) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += (trees[i] > testNum) ? trees[i] - testNum : 0;
		if (sum >= M) return true;
	}

	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<int> trees(N);
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}

	int low = 0;
	int high = 2e9;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		//cout << mid << ' ';
		if (IsValid(mid, trees)) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << high;
	return 0;
}
