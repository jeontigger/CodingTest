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

vector<int> roots;
vector<bool> truth;

int Find(int n) {
	if (n == roots[n]) {
		return n;
	}
	else {
		return roots[n] = Find(roots[n]);
	}
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	//if (a == b) return;

	if (truth[a]) {
		roots[b] = a;
		truth[b] = true;

	}
	else if (truth[b]) {
		roots[a] = b;
		truth[a] = true;
	}
	else {
		roots[a] = b;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Init
	int N, M;
	cin >> N >> M;

	roots.resize(N + 1);
	for (int i = 1; i < N + 1; i++) {
		roots[i] = i;
	}

	int T, t;
	cin >> T;
	truth.resize(N + 1);
	for (int i = 0; i < T; i++) {
		cin >> t;
		truth[t] = true;
	}

	vector<vector<int>> parties(M);
	for (int i = 0; i < M; i++) {
		cin >> T;
		parties[i].resize(T);
		for (int j = 0; j < T; j++) {
			cin >> parties[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 1; j < parties[i].size(); j++) {
			Union(parties[i][j], parties[i][j - 1]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		cnt++;
		for (int j = 0; j < parties[i].size(); j++) {
			int people = parties[i][j];
			if (truth[Find(people)]) {
				cnt--;
				break;
			}
		}
	}

	//PrintVec(parties);
	//PrintVec(truth);

	cout << cnt;

	return 0;
}