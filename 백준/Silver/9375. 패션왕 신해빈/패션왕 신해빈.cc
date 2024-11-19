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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		unordered_map<string, int> clotheCnts;
		string name, kind;
		int N;
		cin >> N;
		while (N--) {
			cin >> name >> kind;
			clotheCnts[kind]++;
		}

		int res = 1;
		for (auto iter = clotheCnts.begin(); iter != clotheCnts.end(); ++iter) {
			res *= (iter->second + 1);
		}

		cout << res - 1 << ' ';
	}

	return 0;
}