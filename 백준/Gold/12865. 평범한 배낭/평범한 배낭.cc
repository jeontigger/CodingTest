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

struct Data {
	int weight;
	int value;
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<Data> items(N);
	vector<int> knaps(K + 1);
	for (int i = 0; i < N; i++) {
		cin >> items[i].weight >> items[i].value;
	}

	for (int i = 0; i < N; i++) {
		int w = items[i].weight;
		int v = items[i].value;
		auto prev = knaps;
		for (int i = w; i <= K; i++) {
			knaps[i] = max(prev[i - w] + v, prev[i]);
		}
		//PrintVec(knaps);
	}

	cout << knaps[K];

	return 0;
}
