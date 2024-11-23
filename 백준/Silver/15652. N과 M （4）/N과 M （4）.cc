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

void PrintMultipleComb(int N, int M, vector<int>& path, int start) {

	if (M == 0) {
		PrintVec(path);
		return;
	}

	for (int i = start; i <= N; i++) {
		path[path.size() - M] = i;
		PrintMultipleComb(N, M - 1, path, i);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> path(M, 1);
	PrintMultipleComb(N, M, path, 1);

	return 0;
}