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

vector<int> visited;

void NM(int N, int idx, int M) {

	if (M == 0) {
		for (int i = 1; i <= N; i++) {
			if (visited[i]) {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}

	for (int i = idx + 1; i <= N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		NM(N, i, M - 1);
		visited[i] = false;
	}



}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	visited.resize(N + 1);

	NM(N, 0, M);


	return 0;
}