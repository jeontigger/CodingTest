#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <set>

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

struct Data {
	int cnt;
	int candy;
};

vector<int> parents;
vector<int> child;
vector<Data> vecCandy;

int Find(int x) {
	if (parents[x] == x) {
		return x;
	}
	else
		return parents[x] = Find(parents[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	parents[a] = b;

	vecCandy[parents[a]].cnt += vecCandy[a].cnt;
	vecCandy[a].cnt = 0;
	vecCandy[parents[a]].candy += vecCandy[a].candy;
	vecCandy[a].candy = 0;
}

bool cmp(const Data& d1, const Data& d2) {
	return d1.cnt < d2.cnt;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 뺏는 친구들은 모두 뺏는다
	// K명 이상이면 안된다

	// 이어져 있는 친구 관계를 설명

	int N, M, K;
	cin >> N >> M >> K;
	child.resize(N + 1);
	vecCandy.resize(N + 1);
	for (int i = 1; i < N + 1; i++) {
		cin >> child[i];
		vecCandy[i].candy = child[i];
		vecCandy[i].cnt = 1;
	}

	int a, b;
	parents.resize(N + 1);
	for (int i = 1; i < N + 1; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		Union(a, b);
	}

	sort(vecCandy.begin(), vecCandy.end(), cmp);

	vector<int>dp(N + 1);

	dp[0] = 0;

	for (int i = 0; i < vecCandy.size(); i++) {
		int curCnt = vecCandy[i].cnt;
		int curVal = vecCandy[i].candy;
		if (curCnt == 0) continue;
		auto pdp = dp;
		for (int i = curCnt; i < K; i++) {
			dp[i] = max(dp[i], pdp[i - curCnt] + curVal);
		}

		//PrintVec(dp);
	}

	cout << *max_element(dp.begin(), dp.end());


	return 0;
}