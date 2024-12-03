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

vector<int> parents;

int Find(int n) {
	if (parents[n] == n) {
		return n;
	}
	else {
		return parents[n] = Find(parents[n]);
	}
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	parents[a] = b;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	parents.resize(N + 1);
	for (int i = 0; i < N + 1; i++) {
		parents[i] = i;
	}

	int truthNum;
	cin >> truthNum;
	vector<int> truths(truthNum);
	for (int i = 0; i < truthNum; i++) {
		cin >> truths[i];
	}
	vector<vector<int>> party(M);
	for (int i = 0; i < M; i++) {
		int peopleNum;
		cin >> peopleNum;

		party[i].resize(peopleNum);
		cin >> party[i][0];
		for (int j = 1; j < peopleNum; j++) {
			cin >> party[i][j];
			Union(party[i][j - 1], party[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		bool canLie = true;

		for (int j = 0; j < party[i].size(); j++) {
			int curPeople = party[i][j];

			for (int k = 0; k < truthNum; k++) {
				if (Find(curPeople) == Find(truths[k])) {
					canLie = false;
					break;
				}
			}

			if (!canLie) {
				break;
			}
		}

		if (canLie) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}