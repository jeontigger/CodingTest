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

int N;
void Inputs() {
	cin >> N;
}

// 11이 S(n)안에 있을 때 n의 최소값 구하기

// S(0) => 3
// S(1) => 3+4+3 = 10
// S(2) => 10 + 5 + 10 = 25
vector<int> lengths;
int GetLevel(int k) {
	int level = 0;
	int length = 3;
	lengths.push_back(length);

	while (length < k) {
		level++;
		length = length * 2 + level + 3;
		lengths.push_back(length);
	}

	return level;
}

string moo = "moo";
char DC(int level, int k) {
	if (level == 0) {
		return moo[k - 1];
	}

	int len = lengths[level - 1];
	int cur = level + 3;

	char ret = ';';
	if (k <= len) {
		ret = DC(level - 1, k);
	}
	else if (k <= len + cur) {
		if (k == len + 1)return 'm';
		else return 'o';
	}
	else {
		ret = DC(level - 1, k - len - cur);
	}

	return ret;
}

void Solution() {

	int level = GetLevel(N);
	cout << DC(level, N);



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