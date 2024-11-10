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

struct Jewelry {
	int w;
	int v;
};

bool Jcmp(const Jewelry& j1, const Jewelry& j2) {
	return j1.w < j2.w;
}

struct cmp {
	bool operator()(const Jewelry& j1, const Jewelry& j2) {
		return j1.v < j2.v;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<Jewelry> jewelries(N);
	for (int i = 0; i < N; i++) {
		cin >> jewelries[i].w >> jewelries[i].v;
	}

	vector<int> bags(K);
	for (int i = 0; i < K; i++) {
		cin >> bags[i];
	}

	sort(jewelries.begin(), jewelries.end(), Jcmp);
	sort(bags.begin(), bags.end());
	vector<int> visited(K);
	priority_queue<Jewelry, vector<Jewelry>, cmp> pq;

	int idx = 0;
	long long sum = 0;
	for (int i = 0; i < K; i++) {
		while ((idx < N) && jewelries[idx].w <= bags[i]) {
			pq.push(jewelries[idx]);
			idx++;
		}

		if (!pq.empty()) {
			sum += pq.top().v;
			pq.pop();
		}
	}

	cout << sum;

	return 0;
}