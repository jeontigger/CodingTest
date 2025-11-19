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

int N, d, k, c, sushi[30000];
void Inputs() {
	cin >> N >> d >> k >> c;
	FOR(i, N)
		cin >> sushi[i];
}

void Solution() {
	unordered_map<int, int> cnts;

	int left = 0, kind = 0, ret = 0;
	for (int right = 0; right < N + k; right++) {
		cnts[sushi[right % N]]++;
		if (cnts[sushi[right % N]] == 1) kind++;

		while (right - left + 1 >= k) {
			// 종류 개수 세기
			int valid = 0;
			if (cnts[c] == 0) valid = 1;
			ret = max(ret, kind + valid);

			// 왼쪽 빼기
			cnts[sushi[left % N]]--;
			if (cnts[sushi[left % N]] == 0) kind--;
			left++;
		}

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