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

bool cards[20000001];

void Mark(int num) {
	cards[num + 10000000] = true;
}
bool Check(int num) {
	return cards[num + 10000000];
}

int N, M;

void Inputs() {
	memset(cards, false, sizeof(cards));
	cin >> N;
	FOR(i, N) {
		int num;
		cin >> num;
		Mark(num);
	}

	cin >> M;
	FOR(i, M) {
		int num;
		cin >> num;
		cout << Check(num) << ' ';
	}
}

void Solution() {
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