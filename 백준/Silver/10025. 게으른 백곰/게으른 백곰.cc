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
#include <iomanip>
#include <cassert>
#include <cstring>
#include <list>

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
#define FOR(idx, limit) for(int idx = 0; idx < limit; idx++)

// 좌표가 최대 1000000(백만)이기 때문에 고정 배열 크기의 슬라이딩 윈도우를 해도 될거같긴 함
// 좌표는 최대 백만이고, 좌우로 2백만 까지 가능하니까 50만이상이면 그냥 전체 합이면 될듯?

// G => 얼음 양, X => 위치
int N, K, G[100000], X[100000];


void Inputs() {
	cin >> N >> K;
	FOR(i, N)
		cin >> G[i] >> X[i];
}

void Solution() {
	if (K >= 500000) {
		int sum = 0;
		for (int g : G) {
			sum += g;
		}
		cout << sum;
		return;
	}


	vector<int> ice(1000001);
	for (int i = 0; i < N; i++) {
		ice[X[i]] = G[i];
	}

	int left = 0, sum = 0, ret = 0;
	for (int right = 0; right < ice.size(); right++) {
		sum += ice[right];

		while (right - left >= 2 * K + 1) {
			sum -= ice[left++];
		}

		ret = max(ret, sum);
	}

	cout << ret << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	//cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}