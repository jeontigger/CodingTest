#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <map>
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

int K;
string str;

void Inputs() {
	cin >> K >> str;
}

struct ACGT {
	int a = 0;
	int c = 0;
	int g = 0;
	int t = 0;

	bool operator<(const ACGT& other) const {
		if (a != other.a) return a < other.a;
		if (c != other.c) return c < other.c;
		if (g != other.g) return g < other.g;
		return t < other.t;
	}
};

void ACGTChange(char ch, ACGT& data, int delta) {
	switch (ch)
	{
	case 'A':
		data.a += delta;
		break;
	case 'C':
		data.c += delta;
		break;
	case 'G':
		data.g += delta;
		break;
	case 'T':
		data.t += delta;
		break;
	default:
		break;
	}
}

void Solution() {
	int N = str.size();
	if (K >= N) {
		cout << 1 << '\n';
		return;
	}

	int left = 0, ret = 0;
	map<ACGT, int> cnts;
	ACGT cur;
	for (int right = 0; right < N; right++) {
		ACGTChange(str[right], cur, 1);

		while (right - left + 1 >= K) {
			ret = max(ret, ++cnts[cur]);
			ACGTChange(str[left++], cur, -1);
		}
	}

	cout << ret << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}