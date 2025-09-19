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

int N, S;
int switches[101];
int s[101], n[101];

void Inputs() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> switches[i];
	}

	cin >> S;
	for (int i = 0; i < S; i++) {
		cin >> s[i] >> n[i];
	}
}

void Flip(int num) {
	if (switches[num] == 0) {
		switches[num] = 1;
	}
	else {
		switches[num] = 0;
	}
}

void Solution() {
	for (int i = 0; i < S; i++) {
		int _s = s[i];
		int _n = n[i];

		if (_s == 1) {
			// 남자라면
			for (int i = _n; i <= N; i += _n) {
				Flip(i);
			}
		}
		else {
			// 여자라면
			Flip(_n);
			int cnt = 1;
			while (true) {
				if (_n - cnt < 1 || _n + cnt > N) break;
				if (switches[_n - cnt] != switches[_n + cnt]) break;
				Flip(_n - cnt);
				Flip(_n + cnt);
				cnt++;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << switches[i];
		if (i % 20 == 0) {
			cout << '\n';
		}
		else {
			cout << ' ';
		}
	}
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