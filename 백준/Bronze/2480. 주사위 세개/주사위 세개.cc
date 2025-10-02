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

int A, B, C;
void Inputs() {
	cin >> A >> B >> C;
}

int Triple(int num) {
	int ret = 0;

	ret += 10000;
	ret += num * 1000;

	return ret;
}

int Double(int num) {
	int ret = 0;

	ret += 1000;
	ret += num * 100;

	return ret;
}

int Single(int num) {
	int ret = 0;

	ret += 100 * num;

	return ret;
}

int GetType(int first, int second, int third) {
	set<int> s;
	s.insert(first);
	s.insert(second);
	s.insert(third);
	return s.size();
}

int cnts[7];

int GetCnt(int num) {
	return cnts[num];
}

void Solution() {
	int type = GetType(A, B, C);
	cnts[A]++;
	cnts[B]++;
	cnts[C]++;

	int value = 0;
	switch (type)
	{
	case 3:
	{
		int maxValue = max(A, max(B, C));
		value = Single(maxValue);
	}
	break;
	case 2:
		if (GetCnt(A) == 2) {
			value = Double(A);
		}
		else {
			value = Double(B);
		}
		break;
	case 1:
		value = Triple(A);
		break;

	default:
		break;
	}

	cout << value << '\n';
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