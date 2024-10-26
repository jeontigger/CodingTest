#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

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

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

struct Data {
	int paper;
	int meet;
};

bool cmp(const Data& d1, const Data& d2) {
	return d1.paper < d2.paper;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	cin >> T;

	while (T) {
		T--;
		cin >> N;

		vector<Data> juniors(N);
		for (int i = 0; i < N; i++) {
			cin >> juniors[i].paper >> juniors[i].meet;
		}

		sort(juniors.begin(), juniors.end(), cmp);

		int cnt = 0;
		int minValue = INF;
		for (int i = 0; i < N; i++) {
			if (minValue > juniors[i].meet) {
				minValue = juniors[i].meet;
				cnt++;
			}
		}

		cout << cnt << " ";

	}



	return 0;
}