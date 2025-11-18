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

int S, P;
string text;
int acgt[4];
void Inputs() {
	cin >> S >> P;
	cin >> text;
	FOR(i, 4)
		cin >> acgt[i];
}

bool Check(const unordered_map<char, int>& cnts) {
	int a = 0, c = 0, g = 0, t = 0;
	for (const auto& [alpha, cnt] : cnts) {
		switch (alpha)
		{
		case 'A':
			a = cnt;
			break;
		case 'C':
			c = cnt;
			break;
		case 'G':
			g = cnt;
			break;
		case 'T':
			t = cnt;
			break;
		default:
			return false;
			break;
		}
	}

	return a >= acgt[0] && c >= acgt[1] && g >= acgt[2] && t >= acgt[3];
}

void Solution() {
	// um으로 추적
	unordered_map<char, int> cnts;

	for (int i = 0; i < P; i++) {
		cnts[text[i]]++;
	}

	int cnt = 0;
	if (Check(cnts)) cnt++;

	for (int i = P; i < S; i++) {
		cnts[text[i - P]]--;
		cnts[text[i]]++;

		if (Check(cnts)) cnt++;
	}

	cout << cnt << '\n';
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