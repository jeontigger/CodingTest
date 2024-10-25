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



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<int> coinsValue(N);
	vector<int> coinsCnt(N);

	for (int i = 0; i < N; i++) {
		cin >> coinsValue[i];
	}

	sort(coinsValue.begin(), coinsValue.end(), greater<int>());

	//PrintVec(coinsValue);

	int money = 0;
	int idx = 0;
	while (money != K) {
		if (money < K) {
			money += coinsValue[idx];
			coinsCnt[idx]++;
		}
		else if (money > K) {
			money -= coinsValue[idx];
			coinsCnt[idx]--;
			idx++;
		}
	}

	int cnt = 0;
	for (int i : coinsCnt) {
		cnt += i;
	}

	cout << cnt;


	return 0;
}