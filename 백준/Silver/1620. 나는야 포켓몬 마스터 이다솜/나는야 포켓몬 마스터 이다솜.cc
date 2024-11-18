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

	int N, M;
	cin >> N >> M;
	vector<string> numToName(N + 1);
	unordered_map<string, int> nameToNum;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		nameToNum[str] = i + 1;
		numToName[i + 1] = str;
	}

	for (int i = 0; i < M; i++) {
		cin >> str;
		if ('0' <= str[0] && str[0] <= '9') {
			cout << numToName[stoi(str)] << ' ';
		}
		else {
			cout << nameToNum[str] << ' ';
		}
	}

	return 0;
}